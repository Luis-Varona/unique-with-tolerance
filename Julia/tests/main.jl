#-
include("../UniqueWithTolerance.jl")
include("TestArray.jl")

using .UniqueWithTolerance: uniquetol
using .TestArray: TESTARRAY

#-
function main()
    (arr_unique, indices_unique, inverse_unique, counts_unique) = uniquetol(
        TESTARRAY;
        return_indices=true, return_inverse=true, return_counts=true,
    )
    
    println("num_total: ", length(TESTARRAY))
    println("num_unique: ", length(arr_unique), "\n")
    println("arr_unique: ", arr_unique, "\n")
    println("indices_unique: ", indices_unique, "\n")
    println("inverse_unique: ", inverse_unique, "\n")
    println("counts_unique: ", counts_unique)
end

main()