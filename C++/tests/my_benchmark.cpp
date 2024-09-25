//
#include <cstdio>
#include <benchmark/benchmark.h>

#include "helpers/testarray.hpp"
#include "../uniquetol.hpp"

//
double *arr = test_array();

static void BM_uniquetol(benchmark::State& state) {
    while (state.KeepRunning()) uniquetol(arr, n);
}

BENCHMARK(BM_uniquetol);
BENCHMARK_MAIN();