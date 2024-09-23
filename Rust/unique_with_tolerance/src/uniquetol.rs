//
#[path = "isapprox.rs"] mod isapprox;
#[path = "sortperm.rs"] mod sortperm;

//
use isapprox::Tols;
use isapprox::isapprox;
use sortperm::sortperm;

//
pub fn uniquetol(arr: &[f64], args: UniqueTolArgs) -> UniqueTolArray {
    let use_highest = args.occurrence == "highest";
    let use_lowest = args.occurrence == "lowest";
    
    if !use_highest && !use_lowest {
        panic!("`occurrence` must be either `highest` or `lowest`");
    }
    
    let n = arr.len();
    if n == 0 {
        return UniqueTolArray {
            arr_unique: Vec::new(),
            indices_unique: Vec::new(),
            inverse_unique: Vec::new(),
            counts_unique: Vec::new(),
        };
    }
    else {
        unimplemented!();
    }
}

//
pub struct UniqueTolArray {
    arr_unique: Vec<f64>,
    indices_unique: Vec<usize>,
    inverse_unique: Vec<usize>,
    counts_unique: Vec<u32>,
}

//
pub struct UniqueTolArgs {
    atol: f64,
    rtol: f64,
    occurrence: &'static str,
}

//
impl Default for UniqueTolArgs {
    fn default() -> UniqueTolArgs {
        UniqueTolArgs {
            atol: 1e-8,
            rtol: (f64::EPSILON).sqrt(),
            occurrence: "highest",
        }
    }
}