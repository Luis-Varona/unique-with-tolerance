module UniqueTolTestArray
    #- EXPORTS AND IMPORTS
    export rand_testarray
    
    include("../UniqueWithTolerance.jl")
    using .UniqueWithTolerance: uniquetol
    
    using Distributions: Uniform
    using Random: shuffle!
    
    #- FUNCTION: `rand_testarray`
    function rand_testarray(k::Int64=100, max_count::Int64=13)
        #-
        num_ones = rand(1:max_count)
        counts_initial = Vector{Int64}(undef, k)
        counts_initial[1:num_ones] .= 1
        counts_initial[(num_ones + 1):k] .= rand(2:max_count, k - num_ones)
        
        #-
        range_values = (rand(-87:-13), rand(13:87))
        values_initial = rand(Uniform(range_values[1], range_values[2]), k)
        
        #-
        range_shifts = (rand(-334:-87), rand(87:334))
        shifts = rand(range_shifts[1]:range_shifts[2], k)
        values_initial .+= shifts
        
        #-
        diffs = map(x -> rand(Uniform(-1e-6, 1e-6), x), counts_initial)
        testarray = vcat([v .+ ct for (v, ct) in zip(values_initial, diffs)]...)
        shuffle!(testarray)
        
        #-
        return testarray
    end
end