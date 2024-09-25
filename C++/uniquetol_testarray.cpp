//
#include <cstdlib>
#include <ctime>

//
double rand_double(double min, double max);

double *rand_testarray(int k, int max_count) {
    srand(time(NULL));
    
    int num_ones = 1 + rand() % max_count;
    
    int value_min = -87 + rand() % 75;
    int value_max = 13 + rand() % 75;
    
    int shift_min = -334 + rand() % 248;
    int shift_max = 87 + rand() % 248;
    
    int n;
    int counts_initial[k];
    int values_initial[k];
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
        
        values_initial[i] = value_min + rand() % (value_max - value_min + 1);
        values_initial[i] += shift_min + rand() % (shift_max - shift_min + 1);
        diffs[i] = new double[ct];
        
        for (int j = 0; j < ct; j++) {
            diffs[i][j] = rand_double(-1e6, 1e6);
        }
    }
    
    double *testarray = new double[n];
    
    for (int i = 0; i < n; i ++) {
        int val = values_initial[i];
        int ct = counts_initial[i];
        double *diffs_chunk = diffs[i];
        
        for (int j = 0; j < ct; j ++) {
            testarray[i + j] = val + diffs_chunk[j];
        }
        
        free(diffs_chunk);
        free(diffs[i]);
        diffs_chunk = NULL;
        diffs[i] = NULL;
    }
    
    return testarray;
}

//
double rand_double(double min, double max) {
    return min + static_cast <double> (rand())
        / (static_cast <double> (RAND_MAX / (max - min)));
}