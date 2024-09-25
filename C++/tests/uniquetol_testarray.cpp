//
#include <cstdio>
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
    
    int counts_initial[k];
    int values_initial[k];
    double *diffs[k]; // Correct syntax?
    
    for (int i = 0; i < num_ones; i++) {
        counts_initial[i] = 1;
    }
    
    for (int i = num_ones; i < k; i++) {
        counts_initial[i] = 2 + rand() % max_count;
    }
    
    for (int i = 0; i < k; i++) {
        values_initial[i] = value_min + rand() % (value_max - value_min + 1);
        values_initial[i] += shift_min + rand() % (shift_max - shift_min + 1);
    }
    
    // ADD LATER
}

//
double rand_double(double min, double max) {
    return min + static_cast <double> (rand())
        / (static_cast <double> (RAND_MAX / (max - min)));
}