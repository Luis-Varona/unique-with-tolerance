include("TestArray.jl")
include("../UniqueWithTolerance.jl")

using .TestArray: TESTARRAY
using .UniqueWithTolerance: uniquetol
using BenchmarkTools: @benchmark

function main()
    bench = @benchmark uniquetol($TESTARRAY)
    io = IOBuffer()
    show(io, "text/plain", bench)
    bench_str = String(take!(io))
    println(bench_str)
end

main()