One application of a binary tree-like structure "in the wild" is in-memory file systems. When we work with files on a desktop computer, the major operating systems all provide an abstraction that's sort of analogous to an actual desk covered with paper files that are organized into folders. This file/folder structure can be represented as a generalization of a binary tree called a B-tree, where each node can have more than two successors. The benefit of this as opposed to storing memory offsets and using, for example, `seekg()`, is that seeking around a whole disk is an expensive operation. With a tree like this, you don't need to seek much forwards and backwards at all, you dereference pointers to exactly where you need to be.

Another application comes from actually parsing a programming language itself. C++ is complicated, but something like Lisp is very simple:

    (+ 1 2)

Lisp functions are all written in prefix notation, so this expression adds together the numbers `1` and `2`. To evaluate this, an interpreter needs to turn this text into some data structure that can be evaluated:

                    function call ( + )
                  /                    \
    operation (addition)          arguments (list of numbers | [1, 2])

This data structure can then be processed with some logic, in loose pseudocode:

    function evaluate(expression tree)
    {
        switch (tree->type)
        {
            case function_call:
                call_function_on_child_nodes(tree->function, tree->children);
            // etc, other types like number, symbol
        }
    }

This kind of data structure is represented as a tree as well, called an Abstract Syntax Tree or AST, and function call nodes are binary trees.

I didn't get this working in C++ for this discussion post, but I copied in some Rust I have for this from an earlier project that serves to demonstrate the concept - in this example, an `Lval` is an AST like described, a `Sexpr` is an "s-expression", or a Lisp-style prefix expression like `(+ 1 2)`, and a `Box` is identical to a C++ `unique_ptr`:

    // Fully evaluate an `Lval`
    pub fn lval_eval(e: &mut Lenv, v: &mut Lval) -> BlisprResult {
        let child_count;
        let mut args_eval;
        match v {
            Lval::Sym(s) => {
                // If it's a symbol like '+', perform an environment lookup
                let result = e.get(&s)?;
                // The environment stores Lvals like Lval::Function(addition) ready to go, we're done
                return Ok(result);
            }
            Lval::Sexpr(ref mut cells) => {
                // If it's a Sexpr, we're going to continue past this match
                // First, though, recursively evaluate each child with lval_eval()
                // grab the length and evaluate the children
                child_count = cells.len();
                args_eval = eval_cells(e, cells)?;
            }
            // if it's not a sexpr, we're done, return as is
            _ => {
                return Ok(Box::new(v.clone()));
            }
        }
        if child_count == 0 {
            // It was a Sexpr, but it was empty.  We're done, return it
            Ok(Box::new(v.clone()))
        } else if child_count == 1 {
            // Single expression
            lval_eval(e, &mut *lval_pop(v, 0)?)
        } else {
            // Function call
            let fp = lval_pop(&mut args_eval, 0)?;
            lval_call(e, *fp, &mut *args_eval)
        }
    }

Because of the tree-like nature, this single function can recursively evaluate all the parts of an expression, because each part gets stored as its own mini sub-tree. You just call this exact same function on each part until it stops recurring and you're done. Passing in `"(+ 1 2)"` will build a data structure like this - not a binary tree, but an AST: `Lval::Sexpr(children: [Lval::Sym('+'), Lval::Num(1), Lval::Num(2)])`., with each node stored as a pointer. Passing that to `lval_eval()` will eventually - after recurring a few times - return `Lval::Num(3)`, which can be pretty-printed out to the user as the answer.  Along the way, you construct an intermediate binary tree object to represent a function call AST node, which might look sort of like this in C++:

    struct FunctionCallASTNode
    {
         NodeVariant type; // function_call
         *Node func; // function pointer
         *Node children: // function arguments, will need to be evaluated
         FunctionCallASTNode(const Node &fp, const Node &args); // Constructor
    }

    // ..

    template <class F>
    template <class N> // both F and N are AST node objects
    unique_ptr<F> AST::make_function_call(const N &fp, const N &args)
    {
        return make_unique(FunctionCallASTNode(fp, args));
    }

It will get created, evaluated, and destroyed before the expression returns to the user.

The AST node for functions themselves, like "addition" in this example stored in `fp` or user-defined functions we interpreted ourselves, might also be a binary tree.   In that case "left" and "right" point to the parameters for the function and the logic for the function, respectively (a.k.a the "formals" and "body").

Works Cited:

“6 C Abstract Syntax Tree (CAST) Representation.” C Abstract Syntax Tree (CAST) Representation, 15 Nov. 1999, https://www.cs.utah.edu/flux/flick/current/doc/guts/gutsch6.html.

“Why B-Tree for File Systems?” Stack Overflow, 10 Sept. 2015, https://stackoverflow.com/questions/32512700/why-b-tree-for-file-systems.\