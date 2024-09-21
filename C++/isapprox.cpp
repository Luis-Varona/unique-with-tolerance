#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isapprox(
    double x,
    double y,
    double atol = 1e-8,
    double rtol = sqrt(nextafter(1, 2) - 1)
) {
    return fabs(x - y) <= fmax(atol, rtol * fmax(fabs(x), fabs(y)));
}