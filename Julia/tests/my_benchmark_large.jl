include("../UniqueWithTolerance.jl")
using .UniqueWithTolerance: uniquetol

using CodecZlib
using JLD2: load
using BenchmarkTools: @benchmark

function main()
    large_testarray = load("Julia/tests/large_testarray.jld2")["large_testarray"]
    bench = @benchmark uniquetol($large_testarray)
    io = IOBuffer()
    show(io, "text/plain", bench)
    println(String(take!(io)))
end

main()