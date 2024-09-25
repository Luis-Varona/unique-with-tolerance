#ifndef UNIQUTETOL_TESTARRAY
#define UNIQUTETOL_TESTARRAY

typedef struct {
    double *testarray;
    int n;
} TestArray;

TestArray rand_testarray(int k, int max_count);
int *randperm(int n);

#endif