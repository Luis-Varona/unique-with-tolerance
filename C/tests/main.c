//
#include <stdio.h>

#include "../uniquetol.h"
#include "testarray.h"

//
const int n = 729;
double test_arr[n];

//
int main() {
    double *test_arr = test_array();
    UniqueTolArray unique_tol_array = uniquetol(test_arr, n);
    
    for (int i = 0; i < unique_tol_array.num_unique; i++) {
        printf("%d: ", i);
        printf("%f\n", unique_tol_array.arr_unique[i]);
    }
}