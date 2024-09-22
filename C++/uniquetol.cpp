//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>

#include "isapprox.hpp"
#include "sortperm.hpp"
#include "uniquetol.hpp"

//
UniqueTolArray uniquetol(
    double *arr,
    int n,
    double atol,
    double rtol,
    std::string occurrence
) {
    int use_highest = occurrence.compare("highest");
    int use_lowest = occurrence.compare("lowest");
    
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
        sortperm(arr, perm_sorted, n);
        
        double arr_sorted[n];
        double c = arr[perm_sorted[0]];
        arr_sorted[0] = c;
        
        int *indices_unique_temp = (int*)malloc(n * sizeof(int));
        indices_unique_temp[0] = 0;
        int num_unique = 1;
        
        for (int i = 1; i < n; i++) {
            double next = arr[perm_sorted[i]];
            arr_sorted[i] = next;
            
            if (!isapprox(c, next, atol, rtol)) {
                c = next;
                indices_unique_temp[num_unique] = i;
                num_unique++;
            }
        }
        
        double arr_unique[num_unique];
        int indices_unique[num_unique];
        int inverse_unique[n];
        int counts_unique[num_unique];
        
        memcpy(indices_unique, indices_unique_temp, num_unique * sizeof(int));
        free(indices_unique_temp);
        indices_unique_temp = NULL;
        
        int index_last = indices_unique[num_unique - 1];
        int count_last = n - index_last;
        counts_unique[num_unique - 1] = count_last;
        
        for (int j = 0; j < count_last; j++) {
            inverse_unique[perm_sorted[index_last + j]] = num_unique - 1;
        }
        
        for (int i = 0; i < num_unique - 1; i++) {
            int index = indices_unique[i];
            int count = indices_unique[i + 1] - index;
            counts_unique[i] = count;
            
            for (int j = 0; j < count; j++) {
                inverse_unique[perm_sorted[index + j]] = i;
            }
        }
        
        if (use_highest == 0) {
            for (int i = 0; i < num_unique - 1; i ++) {
                indices_unique[i] = indices_unique[i + 1] - 1;
            }
            
            indices_unique[num_unique - 1] = n - 1;
        }
        
        for (int i = 0; i < num_unique; i++) {
            int index = perm_sorted[indices_unique[i]];
            arr_unique[i] = arr[index];
            indices_unique[i] = index;
        }
        
        out = (UniqueTolArray){
            .arr_unique = arr_unique,
            .indices_unique = indices_unique,
            .inverse_unique = inverse_unique,
            .counts_unique = counts_unique,
            .num_total = n,
            .num_unique = num_unique
        };
    }
    
    return out;
}