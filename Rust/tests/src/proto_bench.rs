mod testarray;
#[path = "../../unique_with_tolerance/src/uniquetol.rs"] mod uniquetol;

use std::time::Instant;
use testarray::ARR;
use uniquetol::{UniqueTolArgs, uniquetol};

fn main() {
    let arr_ref = &ARR;
    let mut num: i32 = 10;
    num = num.pow(5);
    println!("Number of iterations: {}", num);
    let start = Instant::now();
    
    for _ in 0..num {
        uniquetol(arr_ref, UniqueTolArgs::default());
    }
    // uniquetol(arr_ref, UniqueTolArgs::default());
    
    let elapsed_time = start.elapsed();
    println!("Elapsed time: {:?}", elapsed_time.as_secs_f64());
    // println!("Elapsed time: {:?}", elapsed_time.as_nanos());
}