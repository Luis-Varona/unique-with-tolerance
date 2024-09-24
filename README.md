# unique-with-tolerance

An algorithm to select unique values in imprecise floating-point arrays with tolerance, written in different languages. Given an array of doubles, the `uniquetol` function returns the largest subset of elements such that no pairs are considered approximately equal. (Two numbers `x` and `y` are considered "approximately equal" subject to `atol` and `rtol` if and only if <code>|x - y&#x7c; &leq; max(atol, rtol&#x2022;max(|x|,|y|))</code>.)

Out of the different versions of this project, the `C++` implementation is currently the fastest. The author is currently working on adding functionality for operating along specified axes of multidimensional arrays. (This algorithm was inspired by `MATLAB`'s `uniquetol` function and `NumPy`'s `unique` function.)

**(WORK IN PROGRESSS)**
