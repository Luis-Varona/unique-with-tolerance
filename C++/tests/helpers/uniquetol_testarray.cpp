//
#include <cstdlib>
#include <ctime>

#include "permute.hpp"
#include "uniquetol_testarray.hpp"

//
double rand_double(double min, double max);
int *randperm(int n);

TestArray rand_testarray(int k, int max_count) {
    srand(time(NULL));
    
    int num_ones = 1 + rand() % max_count;
    
    double value_min = static_cast<double>(-87 + rand() % 75);
    double value_max = static_cast<double>(13 + rand() % 75);
    
    int shift_min = -334 + rand() % 248;
    int shift_max = 87 + rand() % 248;
    
    int n;
    int counts_initial[k];
    double values_initial[k];
    double (*diffs[k]);
    
    for (int i = 0; i < num_ones; i++) {
        counts_initial[i] = 1;
    }
    
    for (int i = num_ones; i < k; i++) {
        counts_initial[i] = 2 + rand() % max_count;
    }
    
    for (int i = 0; i < k; i++) {
        int ct = counts_initial[i];
        n += ct;
        
        values_initial[i] = rand_double(value_min + shift_min, value_max + shift_max);
        diffs[i] = new double[ct];
        
        for (int j = 0; j < ct; j++) {
            diffs[i][j] = rand_double(-1e-6, 1e-6);
        }
    }
    
    double *testarray = (double *)malloc(n * sizeof(double));
    int *perm = randperm(n);
    int index = 0;
    
    for (int i = 0; i < k; i ++) {
        double val = values_initial[i];
        int ct = counts_initial[i];
        double *diffs_chunk = diffs[i];
        
        for (int j = 0; j < ct; j ++) {
            testarray[index + j] = val + diffs_chunk[j];
        }
        
        free(diffs_chunk);
        diffs_chunk = NULL;
        index += ct;
    }
    
    permute(testarray, perm, n);
    free(perm);
    perm = NULL;
    
    return (TestArray){testarray, n};
}

//
double rand_double(double min, double max) {
    return min + rand() * (max - min) / RAND_MAX;
}

//
int *randperm(int n) {
    int *perm = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    
    for (int i = 0; i < n; i++) {
        int j = i + rand() % (n - i);
        swap(&perm[i], &perm[j]);
    }
    
    return perm;
}