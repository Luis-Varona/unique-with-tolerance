#include <math.h>
#include "../C/uniquetol.h"

cdef extern from "<math.h>":
    double sqrt(double x)
    double nextafter(double x, double y)

cdef extern from "../C/uniquetol.h":
    struct UniqueTolArgs:
        double atol
        double rtol
        char *occurrence
    
    struct UniqueTolArray:
        double *arr_unique
        int *indices_unique
        int *inverse_unique
        int *count_unique
        int num_total
        int num_unique
    
    UniqueTolArray uniquetol_var(double *arr, int n, UniqueTolArgs args)

cdef uniquetol(
    double *arr,
    int n,
    double atol=1e-8,
    double rtol=sqrt(nextafter(1, 2) - 1),
    char *occurrence="highest"
):
    return uniquetol_var(arr, n, UniqueTolArgs(atol, rtol, occurrence))