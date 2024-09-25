#include <cstdio>
#include "helpers/testarray.hpp"
#include "../uniquetol.hpp"

int main() {
    double *test_arr = test_array();
    UniqueTolArray uniquetol_array = uniquetol(test_arr, n);
    int k = uniquetol_array.num_unique;
    
    printf("arr_unique:\n");
    for (int i = 0; i < k; i++) {
        printf("%d: ", i);
        printf("%f\n", uniquetol_array.arr_unique[i]);
    }
    
    printf("\n\nindices_unique:\n");
    for (int i = 0; i < k; i++) {
        printf("%d: ", i);
        printf("%d\n", uniquetol_array.indices_unique[i]);
    }
    
    printf("\n\ninverse_unique:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        printf("%d\n", uniquetol_array.inverse_unique[i]);
    }
    
    printf("\n\ncounts_unique:\n");
    for (int i = 0; i < k; i++) {
        printf("%d: ", i);
        printf("%d\n", uniquetol_array.counts_unique[i]);
    }
}