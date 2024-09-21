//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "isapprox.h"

//
double max(double x, double y);

bool isapprox_var(double x, double y, Tols in) {
    double atol = in.atol ? in.atol : 1e-8;
    double rtol = in.rtol ? in.rtol : sqrt(nextafter(1, 2) - 1);
    return fabs(x - y) <= max(atol, rtol * max(fabs(x), fabs(y)));
}

//
double max(double x, double y) {
    return x > y ? x : y;
}