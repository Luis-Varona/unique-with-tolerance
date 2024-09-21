//
#include <stdio.h>

#include "../uniquetol.h"
#include "testarray.h"

//
const int n = 729;
double test_arr[n];

int main() {
    double *test_arr = test_array();
    UniqueTolArray unique_tol_array = uniquetol(test_arr, n);
    int k = unique_tol_array.num_unique;
    
    printf("arr_unique:\n");
    for (int i = 0; i < k; i++) {
        printf("%d: ", i);
        printf("%f\n", unique_tol_array.arr_unique[i]);
    }
    
    printf("\n\nindices_unique:\n");
    for (int i = 0; i < k; i++) {
        printf("%d: ", i);
        printf("%d\n", unique_tol_array.indices_unique[i]);
    }
    
    printf("\n\ninverse_unique:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        printf("%d\n", unique_tol_array.inverse_unique[i]);
    }
    
    printf("\n\ncounts_unique:\n");
    for (int i = 0; i < k; i++) {
        printf("%d: ", i);
        printf("%d\n", unique_tol_array.counts_unique[i]);
    }
}