mod testarray;
#[path = "../../unique_with_tolerance/src/uniquetol.rs"] mod uniquetol;

use std::time::Instant;
use testarray::ARR;
use uniquetol::{UniqueTolArgs, uniquetol};

fn main() {
    let mut num: i32 = 10;
    num = num.pow(5);
    println!("Number of iterations: {}", num);
    let now = Instant::now();
    
    for _ in 0..num {
        uniquetol(&ARR, UniqueTolArgs::default());
    }
    
    let elapsed_time = now.elapsed();
    println!("Elapsed time: {:?}", elapsed_time.as_secs_f64());
}