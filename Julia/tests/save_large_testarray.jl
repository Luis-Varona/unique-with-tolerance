include("../UniqueTolTestArray.jl")
using .UniqueTolTestArray: rand_testarray

using CodecZlib
using JLD2: jldsave

function main()
    large_testarray = rand_testarray(8124, 437)
    jldsave("Julia/tests/large_testarray.jld2", true; large_testarray)
end

main()