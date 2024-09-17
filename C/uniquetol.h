#ifndef UNIQUETOL
#define UNIQUETOL

#include <stdio.h>
#include "isapprox.h"

typedef struct {
    double* arr_unique;
    int* indices_unique;
    int* inverse_unique;
    int* counts_unique;
} UniqueTolArray;

#endif