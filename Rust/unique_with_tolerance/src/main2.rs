use unique_with_tolerance::sortperm::sortperm;

fn main() {
    let arr = vec![3.0, 1.0, 4.0, 1.0, 5.0, 9.0, 2.0, 6.0, 5.0, 3.0];
    let perm = sortperm(&arr);
    println!("{:?}", perm);
}