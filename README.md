# blackboardBold

A project to provide simple class definitions for common mathematical objects.

The name refers to the convention of using Blackboard Bold capital letters to denote different mathematical sets. Off the top of my head we have:

- N for the natural numbers
- Z for the integers. From the german 'Zahl'
- Q for rational numbers
- R for real numbers
- C for complex numbers

Of course most of these already have definitions in the standard c++ library, but I cannot seem to find a standard library for rational numbers that suits my purpose.
And I'm tired of rewriting a new rational class for every project. So I'm going to start with Q and see where I end up. If nothing else this will be a convenient place to copy and paste from.

The long term plan is to explore arbitrary precision arithmetic and possible implement some kind of set builder notation. Of course no plan survives contact with the enemy.

## Update September 26, 2024

Alright it looks like this is going to be a place for me to store stuff for reuse. The two goals for the immediate future are as follows:

- A parser
  - accepts a string as an input
  - outputs a callable function using the std::functional library
  - handle all standard functions and operations
  - remain type agnostic
- A tensor operations library
  - Fully general would be nice but scalars, vectors, and matrices are the priority.

## Update July 5, 2025

Because I've done such a great job failing to accomplish my other goals, I'm now going to add another one.

- zmod, a light weight, POD-like, class template for cyclic groups.
- Also, I've discovered that Eigan already implements most, if not all, of what I want with respect to tensors, so hold the tensor operations library.
