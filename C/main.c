#include <stdio.h>
#include "isapprox.h"

int main() {
    double a = 3.14;
    double b = 3.14 + 1e-8;
    
    if (isapprox(a, b)) {
        printf("a and b are approximately equal\n");
    } else {
        printf("a and b are not approximately equal\n");
    }
    
    double x = 13.2;
    double y = 13.3;
    
    if (isapprox(x, y, 1e-3, 1e-5)) {
        printf("x and y are approximately equal\n");
    } else {
        printf("x and y are not approximately equal\n");
    }
}