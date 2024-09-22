//
#include <stdbool.h>
#include <math.h>
#include "isapprox.h"

//
double max(double x, double y) {
    return x > y ? x : y;
}

//
bool isapprox_var(double x, double y, Tols tols) {
    double atol = tols.atol ? tols.atol : 1e-8;
    double rtol = tols.rtol ? tols.rtol : sqrt(nextafter(1, 2) - 1);
    return fabs(x - y) <= max(atol, rtol * max(fabs(x), fabs(y)));
}