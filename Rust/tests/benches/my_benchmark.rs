#[path = "../src/testarray.rs"] mod testarray;
#[path = "../../unique_with_tolerance/src/uniquetol.rs"] mod uniquetol;

use criterion::{black_box, criterion_group, criterion_main, Criterion};
use testarray::ARR;
use uniquetol::{UniqueTolArgs, uniquetol};

fn criterion_benchmark(c: &mut Criterion) {
    c.bench_function(
        "uniquetol testarray",
        |b| b.iter(|| uniquetol(black_box(&ARR), UniqueTolArgs::default())),
    );
}

criterion_group!(benches, criterion_benchmark);
criterion_main!(benches);