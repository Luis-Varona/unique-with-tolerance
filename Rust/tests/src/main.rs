mod testarray;
#[path = "../../unique_with_tolerance/src/uniquetol.rs"] mod uniquetol;

use testarray::ARR;
use uniquetol::{UniqueTolArgs, uniquetol};

fn main() {
    let uniquetol_array = uniquetol(&ARR, UniqueTolArgs::default());
    
    println!("num_total: {}", uniquetol_array.arr_unique.len());
    println!("num_unique: {}\n", uniquetol_array.indices_unique.len());
    
    println!("arr_unique: {:?}\n", uniquetol_array.arr_unique);
    println!("indices_unique: {:?}\n", uniquetol_array.indices_unique);
    println!("inverse_unique: {:?}\n", uniquetol_array.inverse_unique);
    println!("counts_unique: {:?}", uniquetol_array.counts_unique);
}