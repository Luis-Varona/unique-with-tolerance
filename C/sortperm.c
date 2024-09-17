//
#include <stdio.h>
#include <stdlib.h>

//
int compare(double* arr, const void* p, const void* q) {
    int result;
    
    if (arr[*(int*)p] - arr[*(int*)q] > 0) {
        result = 1;
    }
    else {
        result = -1;
    }
    
    return result;
}

int compare_wrapper(const void* p, const void* q) {
    extern double* global_arr;
    return compare(global_arr, p, q);
}

double* global_arr;

//
void sortperm(double* arr, int n, int* perm) {
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    
    global_arr = arr;
    qsort(perm, n, sizeof(int), compare_wrapper);
}