#ifndef UNIQUETOL
#define UNIQUETOL

typedef struct{
    double atol;
    double rtol;
    char *occurrence;
} UniqueTolArgs;

typedef struct {
    double *arr_unique;
    int *indices_unique;
    int *inverse_unique;
    int *counts_unique;
    int num_total;
    int num_unique;
} UniqueTolArray;

#define uniquetol(arr, n, ...) uniquetol_var(arr, n, (UniqueTolArgs){__VA_ARGS__})
UniqueTolArray uniquetol_var(double *arr, int n, UniqueTolArgs args);

#endif