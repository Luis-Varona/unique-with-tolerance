#ifndef UNIQUETOL
#define UNIQUETOL

#include <math.h>
#include <string>

typedef struct {
    double *arr_unique;
    int *indices_unique;
    int *inverse_unique;
    int *counts_unique;
    int num_total;
    int num_unique;
} UniqueTolArray;

UniqueTolArray uniquetol(
    double *arr,
    int n,
    double atol = 1e-8,
    double rtol = sqrt(nextafter(1, 2) - 1),
    std::string occurrence = "highest"
);

#endif