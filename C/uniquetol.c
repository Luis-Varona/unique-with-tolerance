//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    int use_highest = strcmp(occurrence, "highest");
    int use_lowest = strcmp(occurrence, "lowest");
    
    if (use_highest != 0 && use_lowest != 0) {
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
        
        int* indices_unique_temp = (int*)malloc(n * sizeof(int));
        int length = 0;
        int i = 0;
        int j = 1;
        
        while (j < n) {
            double c = arr_sorted[i];
            bool is_close = true;
            
            while (is_close && j < n) {
                is_close = isapprox(c, arr_sorted[j], atol, rtol);
                j++;
            }
            
            i = j - 1;
            if (!is_close) {
                indices_unique_temp[length] = i;
                length++;
            }
        }
        
        int* indices_unique = (int*)realloc(indices_unique_temp, length * sizeof(int));
        // CONTINUE HERE
    }
}