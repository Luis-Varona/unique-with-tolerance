//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>

#include "isapprox.h"
#include "sortperm.h"
#include "uniquetol.h"

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
        3; // ADD LATER
    }
}