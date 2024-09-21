//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "isapprox.h"
#include "sortperm.h"
#include "uniquetol.h"

//
UniqueTolArray uniquetol_base(
    double *arr,
    int n,
    double atol,
    double rtol,
    char *occurrence
);

//
UniqueTolArray uniquetol_var(double *arr, int n, UniqueTolArgs in) {
    double atol_out = in.atol ? in.atol : 1e-8;
    double rtol_out = in.rtol ? in.rtol : sqrt(nextafter(1, 2) - 1);
    char *occurrence_out = in.occurrence ? in.occurrence : "highest";
    return uniquetol_base(arr, n, atol_out, rtol_out, occurrence_out);
}

//
UniqueTolArray uniquetol_base(
    double *arr,
    int n,
    double atol,
    double rtol,
    char *occurrence
) {
    int use_highest = strcmp(occurrence, "highest");
    int use_lowest = strcmp(occurrence, "lowest");
    
    if (use_highest != 0 && use_lowest != 0) {
        fprintf(stderr, "`occurrence` must be either `highest` or `lowest`");
        exit(1);
    }
    
    UniqueTolArray out;
    
    if (n == 0) {
        double arr_unique[0] = {};
        int indices_unique[0] = {};
        int inverse_unique[0] = {};
        int counts_unique[0] = {};
        
        out = (UniqueTolArray){
            .arr_unique = arr_unique,
            .indices_unique = indices_unique,
            .inverse_unique = inverse_unique,
            .counts_unique = counts_unique,
            .num_total = 0,
            .num_unique = 0
        };
    }
    else {
        int perm_sorted[n];
        double arr_sorted[n];
        int inverse_unique[n];
        int *indices_unique_temp = (int*)malloc(n * sizeof(int));
        int i = 0; int j = 1; int k = 0;
        sortperm(arr, perm_sorted, n);
        
        for (int i = 0; i < n; i++) {
            arr_sorted[i] = arr[perm_sorted[i]];
        }
        
        while (j < n) {
            double c = arr_sorted[i];
            bool is_close = true;
            
            while (is_close && j < n) {
                is_close = isapprox(c, arr_sorted[j], atol, rtol);
                j++;
            }
            
            i = j - 1;
            
            if (!is_close) {
                indices_unique_temp[k] = i;
                k++;
            }
        }
        
        double arr_unique[k];
        int counts_unique[k];
        int *indices_unique = (int*)realloc(indices_unique_temp, k * sizeof(int));
        counts_unique[k] = n - indices_unique[k];
        
        for (int i = 0; i < k - 1; i++) {
            counts_unique[i] = indices_unique[i + 1] - indices_unique[i];
        }
        
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < counts_unique[i]; j++) {
                inverse_unique[indices_unique[i] + j] = i;
            }
        }
        
        if (use_highest == 0) {
            for (int i = 0; i < k - 1; i ++) {
                indices_unique[i] = indices_unique[i + 1] - 1;
            }
            
            indices_unique[k - 1] = n - 1;
        }
        
        for (int i = 0; i < k; i++) {
            indices_unique[i] = perm_sorted[indices_unique[i]];
        }
        
        for (int i = 0; i < k; i++) {
            arr_unique[i] = arr[indices_unique[i]];
        }
        
        out = (UniqueTolArray){
            .arr_unique = arr_unique,
            .indices_unique = indices_unique,
            .inverse_unique = inverse_unique,
            .counts_unique = counts_unique,
            .num_total = n,
            .num_unique = k
        };
    }
    
    return out;
}