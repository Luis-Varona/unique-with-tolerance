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
    let mut out = UniqueTolArray {
        arr_unique: Vec::new(),
        indices_unique: Vec::new(),
        inverse_unique: Vec::new(),
        counts_unique: Vec::new(),
    };
    
    if n > 0 {
        let perm_sorted = sortperm(arr);
        let mut arr_sorted = Vec::with_capacity(n);
        let mut c = arr[perm_sorted[0]];
        arr_sorted.push(c);
        
        let mut indices_unique = Vec::with_capacity(n);
        indices_unique.push(0);
        let mut num_unique = 1;
        
        for i in 1..n {
            let next = arr[perm_sorted[i]];
            arr_sorted.push(next);
            
            if !isapprox(c, next, Tols { atol: args.atol, rtol: args.rtol }) {
                c = next;
                indices_unique.push(i);
                num_unique += 1;
            }
        }
        
        let mut arr_unique = Vec::with_capacity(num_unique);
        let mut inverse_unique = vec![0; n];
        let mut counts_unique = Vec::with_capacity(num_unique);
        
        indices_unique = indices_unique.into_boxed_slice().into_vec();
        let index_last = indices_unique[num_unique - 1];
        let count_last = n - index_last;
        
        for j in 0..count_last {
            inverse_unique[perm_sorted[index_last + j]] = num_unique - 1;
        }
        
        for i in 0..(num_unique - 1) {
            let index = indices_unique[i];
            let count = indices_unique[i + 1] - index;
            counts_unique.push(count);
            
            for j in 0..count {
                inverse_unique[perm_sorted[index + j]] = i;
            }
        }
        
        counts_unique.push(count_last);
        
        if use_highest {
            for i in 0..(num_unique) {
                indices_unique[i] = perm_sorted[indices_unique[i]];
            }
            
            indices_unique[num_unique - 1] = n - 1;
        }
        
        for i in 0..num_unique {
            let index = perm_sorted[indices_unique[i]];
            arr_unique.push(arr_sorted[index]);
            indices_unique[i] = index;
        }
        
        out = UniqueTolArray {
            arr_unique: arr_unique,
            indices_unique: indices_unique,
            inverse_unique: inverse_unique,
            counts_unique: counts_unique,
        };
    }
    
    return out;
}

//
pub struct UniqueTolArray {
    pub arr_unique: Vec<f64>,
    pub indices_unique: Vec<usize>,
    pub inverse_unique: Vec<usize>,
    pub counts_unique: Vec<usize>,
}

//
pub struct UniqueTolArgs {
    pub atol: f64,
    pub rtol: f64,
    pub occurrence: &'static str,
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