#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isapprox(
    double x,
    double y,
    double atol,
    double rtol
) {
    return fabs(x - y) <= fmax(atol, rtol * fmax(fabs(x), fabs(y)));
}