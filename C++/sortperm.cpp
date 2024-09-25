#include <cstdio>
#include <cstdlib>
#include <algorithm>

void sortperm(double *arr, int *perm, int n) {
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    
    struct {
        double *arr;
        bool operator()(int i, int j) {
            return arr[i] < arr[j];
        }
    } Compare = {arr};
    
    std::sort(perm, perm + n, Compare);
}