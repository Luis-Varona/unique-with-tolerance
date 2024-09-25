#include <cstdlib>
#include <cstdbool>
#include <cmath>

bool isapprox(
    double x,
    double y,
    double atol,
    double rtol
) {
    return fabs(x - y) <= fmax(atol, rtol * fmax(fabs(x), fabs(y)));
}