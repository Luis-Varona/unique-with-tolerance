# uniquetol.cpp

The C++ version of the algorithm, where `uniquetol.cpp` is the algorithm proper. The `tests` subfolder contains three files: `testarray.hpp`, `main.cpp`, and `benchmark_main.cpp`. `testarray.hpp` contains a function that outputs a fixed 729-element array with several bundles of approximately equal elements. `tests/main.cpp` contains a test case of the `uniquetol` function  on said array, and `tests/my_benchmark.cpp` runs `uniquetol` on the array 1 million times and checks the total time elapsed (approximately 60&ndash;61 seconds).
