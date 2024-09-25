include("helpers/TestArray.jl")
include("../UniqueWithTolerance.jl")

using .TestArray: TESTARRAY
using .UniqueWithTolerance: uniquetol
using BenchmarkTools: @benchmark

function main()
    bench = @benchmark uniquetol($TESTARRAY)
    io = IOBuffer()
    show(io, "text/plain", bench)
    println(String(take!(io)))
end

main()