# unique-with-tolerance

An algorithm to select unique values in arrays of imprecise floating-point data within a given tolerance, written in different languages. Given an array of numbers, the algorithm returns its largest subset in which no pairs of elements are approximately equal. Two numbers `x` and `y` are "approximately equal" within an absolute tolerance `atol` or a relative tolerance `rtol` if and only if <code>|x&#8239;-&#8239;y|&#8239;&leq;&#8239;max(atol,&#8239;rtol&#8239;&sdot;&#8239;max(|x|,&#8239;|y|))</code>.

A stable version for 1D arrays has been completed in several languages (although certain optimization steps remain). Out of these, the `C++` implementation is the fastest. I am currently adding functionality for operating along specified axes of multidimensional arrays and packaging the project into language-specific libraries.

This algorithm was inspired by `MATLAB`'s `uniquetol` function and `NumPy`'s `unique` function.

**(WORK IN PROGRESSS)**
