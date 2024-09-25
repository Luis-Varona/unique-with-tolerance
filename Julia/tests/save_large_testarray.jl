include("UniqueTolTestArray.jl")
using .UniqueTolTestArray: rand_testarray

using CodecZlib
using JLD2: jldsave

function main()
    k = 8124
    max_count = 437
    large_testarray = rand_testarray(k, max_count)
    jldsave("Julia/tests/large_testarray.jld2", true; large_testarray)
end

main()