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
