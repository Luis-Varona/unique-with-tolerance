//
#include <stdio.h>
#include <time.h>
#include "isapprox.h"

//
double pi = 3.14159265;
double x = 3.14159265 + 4e-7;
double y = 3.14159265 * (1 + 1e-8);

int main() {
        double start_clock_x = clock();
    for (int i = 0; i < 1e9; i++) {
        isapprox(pi, x);
    }
    double end_clock_x = clock();
    
    double start_clock_y = clock();
    for (int i = 0; i < 1e9; i++) {
        isapprox(pi, y);
    }
    double end_clock_y = clock();
    
    double elapsed_time_x = (end_clock_x - start_clock_x) / CLOCKS_PER_SEC;
    double elapsed_time_y = (end_clock_y - start_clock_y) / CLOCKS_PER_SEC;
    
    printf("Elapsed time for x: %f\n", elapsed_time_x);
    printf("Elapsed time for y: %f\n", elapsed_time_y);
}