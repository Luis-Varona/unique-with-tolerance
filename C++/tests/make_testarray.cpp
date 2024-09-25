#include <cstdio>
#include <cstdlib>
#include "helpers/uniquetol_testarray.hpp"

int main() {
    int k = 8124;
    int max_count = 437;
    
    TestArray out = rand_testarray(k, max_count);
    double *testarray = out.testarray;
    int n = out.n;
    
    for (int i = 0; i < n; i++) {
        printf("%f\n", testarray[i]);
    }
    
    printf("\nn = %d\n", n);
}