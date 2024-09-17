//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "isapprox.h"

//
double max(double x, double y) {
    return x > y ? x : y;
}

//
bool isapprox_base(double x, double y, double atol, double rtol) {
    if (atol < 0) {
        fprintf(stderr, "`atol` must be non-negative");
        exit(1);
    }
    if (rtol < 0) {
        fprintf(stderr, "`rtol` must be non-negative");
        exit(1);
    }
    return fabs(x - y) <= max(atol, rtol * max(fabs(x), fabs(y)));
}

//
bool isapprox_var(double x, double y, Tols in) {
    double atol_out = in.atol ? in.atol : 1e-8;
    double rtol_out = in.rtol ? in.rtol : 1e-5;
    return isapprox_base(x, y, atol_out, rtol_out);
}