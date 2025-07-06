# blackboardBold

Welcome to blackboardBold, a project to provide simple class definitions for common mathematical objects.

The name refers to the convention of using Blackboard Bold capital letters to denote different mathematical sets. Off the top of my head we have:

- N for the natural numbers
- Z for the integers. From the german 'Zahl'
- Q for rational numbers
- R for real numbers
- C for complex numbers

Obviously most of these already have well established analogues, the goal of this repository is to fill in the blanks.
To that end we provide class definitions and/or class templates for the following:

- rat, a class for rational numbers.
- znz, a class template for Z/nZ. Currently in development.

The goal in all cases is to match the behavior of the class, as closely as possible, to the behavior of the corresponding mathematical object,
in a way that is computationally safe and efficient.
