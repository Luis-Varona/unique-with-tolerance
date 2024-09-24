# unique-with-tolerance

An algorithm to select unique values in arrays of imprecise floating-point data within a given tolerance, written in different languages. Given an array of numbers, the `uniquetol` function returns its largest subset in which no pairs of elements are approximately equal. Two numbers `x` and `y` are considered "approximately equal" within an absolute tolerance `atol` or a relative tolerance `rtol` if and only if <code>|x - y| &leq; max(atol, rtol&#x2022;max(|x|,|y|))</code>.

A stable algorithm for 1D arrays has been completed and implemented in several languages (although certain optimization steps remain). Out of these, the `C++` version is the fastest. I am currently working on adding functionality for operating along given axes of multidimensional arrays and packaging the algorithm into language-specific libraries.

This algorithm was inspired by `MATLAB`'s `uniquetol` function and `NumPy`'s `unique` function.

**(WORK IN PROGRESSS)**
