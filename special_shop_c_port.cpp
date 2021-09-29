
// gross, but should be good enough to get this to compile...
#define _ALLOW_COMPILER_AND_STL_VERSION_MISMATCH
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cmath>

// type large enough to hold all potential input/output values, as well as intermediate calculations
//typedef int64_t working_type;
using working_type = int64_t;

static double solve_parabola(double x_coord, double a, double b, double c) {
    const double a_term = a * x_coord * x_coord;
    const double b_term = b * x_coord;
    return a_term + b_term + c;
}

/*
Actual solution: 
Q = (A + B)X^2 - 2BNX + B*N^2
a = A + B
b = -2 * B * N
c = B

min x value (real) = -b / 2a
= -2BN / 2(A + B)
= -BN / (A + B)

Solve for q
Round to nearest int
*/

static working_type solve_case(working_type num_pots, double x_mult,
                               double y_mult) 
{
    const double quad_a = x_mult + y_mult;
    const double quad_b = -2 * y_mult * num_pots;
    const double quad_c = y_mult * num_pots * num_pots;
    const double parabola_min_x_coord = std::round(-quad_b / (2 * quad_a));
    const double parabola_min_y_coord = 
        solve_parabola(parabola_min_x_coord, quad_a, quad_b, quad_c);

    const working_type num_x_pots = static_cast<working_type>(std::round(parabola_min_y_coord));
    return num_x_pots;
}

static void read_test_case() {
    working_type pots_to_buy;
    working_type x_cost;
    working_type y_cost;
    std::scanf("%lld %lld %lld", &pots_to_buy, &x_cost, &y_cost);
    const working_type soln = solve_case(pots_to_buy, x_cost, y_cost);
    std::printf("%lld\n", soln);
}

int main() {
    working_type num_problems;
    std::scanf("%lld", &num_problems);

    for(working_type i = 0; i < num_problems; ++i) {
        read_test_case();
    }
}
