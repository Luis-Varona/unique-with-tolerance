# unique-with-tolerance

An algorithm to select unique values in arrays of imprecise floating-point data within a given tolerance, written in different languages. Given an array of numbers, the algorithm returns its largest subset in which no pairs of elements are approximately equal. Here two numbers `x` and `y` are said to be "approximately equal" within an absolute tolerance `atol` or a relative tolerance `rtol` if and only if <code>|x - y| &leq; max(atol, rtol&#8729;max(|x|, |y|))</code>.

A stable version for 1D arrays has been completed in several languages (although certain optimization steps remain). Out of these, the C++ implementation is the fastest. Right now, the algorithm finishes running within a reasonable time frame (less than a minute) on arrays of up to 2 million doubles in all implemented languages. I am currently adding functionality for operating along specified axes of multidimensional arrays and packaging the project into language-specific libraries.

This project was inspired by the `uniquetol` function in MATLAB and NumPy's `unique` function in Python.

**(WORK IN PROGRESSS)**
