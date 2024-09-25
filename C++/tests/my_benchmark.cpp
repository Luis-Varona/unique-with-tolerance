#include <cstdio>
#include <ctime>

#include "helpers/testarray.hpp"
#include "../uniquetol.hpp"

int main() {
    double *test_arr = test_array();
    double start_clock = clock();
    
    for (int i = 0; i < 1e6; i++) {
        uniquetol(test_arr, n);
    }
    
    double end_clock = clock();
    double elapsed_time = (end_clock - start_clock) / CLOCKS_PER_SEC;
    
    printf("Elapsed time: %f\n", elapsed_time);
}