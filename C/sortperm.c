//
#include <stdlib.h>

//
double *global_arr;
int compare(const void *p, const void *q);

void sortperm(double *arr, int *perm, int n) {
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    
    global_arr = arr;
    qsort(perm, n, sizeof(int), compare);
}

//
int compare(const void *p, const void *q) {
    extern double *global_arr;
    int result;
    
    if (global_arr[*(int*)p] - global_arr[*(int*)q] > 0) {
        result = 1;
    }
    else {
        result = -1;
    }
    
    return result;
}