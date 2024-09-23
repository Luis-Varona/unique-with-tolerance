use unique_with_tolerance::isapprox::Tols;
use unique_with_tolerance::isapprox::isapprox;

fn main() {
    let x = 3.14159265;
    let y = x + 4e-9;
    
    // let result = isapprox(x, y, Tols::default());
    let result = isapprox(x, y, Tols {
        atol: 1e-8,
        rtol: 1e-8,
    });
    
    println!("{result}");
}