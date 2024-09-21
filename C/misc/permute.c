//
#include <stdlib.h>

//
void swap(double *a, double *b);

//
void permute(double *arr, int *perm, int n) {
    int inv_perm[n];
    
    for (int i = 0; i < n; i++) {
        inv_perm[perm[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int j = i;
        
        while (inv_perm[j] != -1) {
            swap(&arr[i], &arr[inv_perm[j]]);
            int idx_temp = inv_perm[j];
            inv_perm[j] = -1;
            j = idx_temp;
        }
    }
}

//
void permute_inverse(double *arr, int *perm, int n) {
    for (int i = 0; i < n; i++) {
        int j = i;
        
        while (perm[j] != -1) {
            swap(&arr[i], &arr[perm[j]]);
            int idx_temp = perm[j];
            perm[j] = -1;
            j = idx_temp;
        }
    }
}

//
void swap(double *p, double *q) {
    double temp = *p;
    *p = *q;
    *q = temp;
}