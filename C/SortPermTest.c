#include <stdio.h>
#include "sortperm.h"

int main() {
    const int n = 7;
    double arr[n] = {4.0, 12.0, -15.5, 3.0, 4.0, 11.1, 11.0};
    int perm[n];
    sortperm(arr, n, perm);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
}