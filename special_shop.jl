

function construct_eq(newEq, numPots :: Int64, aMult :: Int64, bMult :: Int64)
    newEq.coeffA = convert(Float64, aMult + bMult);
    newEq.coeffB = convert(Float64, -2 * bMult * numPots);
    newEq.coeffC = convert(Float64, bMult * (numPots ^ 2));
end

struct Equation
    coeffA :: Float64
    coeffB :: Float64
    coeffC :: Float64
    Equation(numPots :: Int64, aMult :: Int64, bMult :: Int64) = 
        construct_eq(new(), numPots, aMult, bMult)
end

function find_equation_min(eq :: Equation)
    numer = -eq.coeffB
    denom = 2 * eq.coeffA
    return numer / denom
end

function solve_equation_at(eq :: Equation, coord :: Float64)
    aTerm = eq.coeffA * (coord ^ 2)
    bTerm = eq.coeffB * coord
    cTerm = eq.coeffC
    return aTerm + bTerm + cTerm
end

function solve_case(numPots, aMult, bMult) 
    eq = Equation(numPots, aMult, bMult);
    eq_min = find_equation_min(eq)
    soln = solve_equation_at(eq, round(eq_min))
    return round(soln)
end

function run_case() 
    test_case_data = [parse(Int, x) for x in split(readline())];
    soln = solve_case(test_case_data[0], test_case_data[1], test_case_data[2]);
    println(soln);
end

function main_fn()
    num_ranges = parse(Int, readline());

    for i in 1:num_ranges
        run_case();
    end

    return nothing
end

main_fn();