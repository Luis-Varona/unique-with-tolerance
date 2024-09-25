//
#[path = "../src/testarray.rs"] mod testarray;
#[path = "../../unique_with_tolerance/src/uniquetol.rs"] mod uniquetol;

use criterion::{black_box, criterion_group, criterion_main, Criterion};
use testarray::ARR;
use uniquetol::{UniqueTolArgs, uniquetol};

//
fn criterion_benchmark(c: &mut Criterion) {
    c.bench_function(
        "uniquetol testarray",
        |b| b.iter(|| uniquetol(black_box(&ARR), UniqueTolArgs::default())),
        // |b| b.iter(|| uniquetol_test(black_box(&ARR), black_box(100000))),
    );
}

criterion_group!(benches, criterion_benchmark);
criterion_main!(benches);

// //
// fn uniquetol_test(arr: &[f64], num_iters: usize) {
//     for i in 0..num_iters {
//         uniquetol(arr, UniqueTolArgs::default());
//     }
// }