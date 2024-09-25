include("../UniqueWithTolerance.jl")
using .UniqueWithTolerance: uniquetol

using CodecZlib
using JLD2: load

function main()
    large_testarray = load("Julia/tests/helpers/large_testarray.jld2")["large_testarray"]
    
    (arr_unique, indices_unique, inverse_unique, counts_unique) = uniquetol(
        large_testarray;
        return_indices=true, return_inverse=true, return_counts=true,
    )
    
    println("num_total: ", length(large_testarray))
    println("num_unique: ", length(arr_unique), "\n")
end

main()