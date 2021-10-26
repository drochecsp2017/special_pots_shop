
local function make_equation(num_pots, a_mult, b_mult)
    return {
        a = a_mult + b_mult,
        b = -2 * b_mult * num_pots,
        c = b_mult * (num_pots ^ 2)
    }
end

local function find_eq_min(eq)
    local numerator = -eq.b
    local denominator = 2 * eq.a
    return numerator / denominator
end

-- Lua doesn't have a round function, so we need a workaround
local function round(value)
    return math.floor(value + .5)
end

local function solve_eq_at(eq, coord)
    local term_a = eq.a * (coord ^ 2)
    local term_b = eq.b * coord
    return term_a + term_b + eq.c
end

local function solve_range(num_pots, a_mult, b_mult)
    local eq = make_equation(num_pots, a_mult, b_mult)
    local eq_min = find_eq_min(eq)
    local soln = solve_eq_at(eq, round(eq_min))
    return round(soln)
end

local function run_case()
    local num_pots = io.read("*n")
    local a_mult = io.read("*n")
    local b_mult = io.read("*n")
    local soln = solve_range(num_pots, a_mult, b_mult)
    io.write(soln, '\n')
end

local function main()
    local num_questions = io.read("*n")
    for i = 0, num_questions - 1 do
        run_case()
    end
end

main()