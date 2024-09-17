//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "isapprox.h"
#include "sortperm.h"
#include "uniquetol.h"

//
UniqueTolArray uniquetol_base(
    double* arr,
    int n,
    double atol,
    double rtol,
    char* occurrence
) {
    if (occurrence != "highest" && occurrence != "lowest") {
        fprintf(stderr, "`occurrence` must be either `highest` or `lowest`");
        exit(1);
    }
    
    if (n == 0) {
        double arr_unique[0] = {};
        int indices_unique[0] = {};
        int inverse_unique[0] = {};
        int counts_unique[0] = {};
        
        UniqueTolArray out = {arr_unique, indices_unique, inverse_unique, counts_unique};
    }
    else {
        int perm_sorted[n];
        sortperm(arr, n, perm_sorted);
        
        double arr_sorted[n];
        for (int i = 0; i < n; i++) {
            arr_sorted[i] = arr[perm_sorted[i]];
        }
        
        // meow
    }
}