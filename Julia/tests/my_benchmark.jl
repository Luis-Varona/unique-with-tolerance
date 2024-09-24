#-
include("../UniqueWithTolerance.jl")
include("TestArray.jl")

using .UniqueWithTolerance: uniquetol
using .TestArray: TESTARRAY
using BenchmarkTools

#-
function main()
    bench = @benchmark uniquetol(TESTARRAY)
    io = IOBuffer()
    show(io, "text/plain", bench)
    bench_str = String(take!(io))
    println(bench_str)
end

# main()