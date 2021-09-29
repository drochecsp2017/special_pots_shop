
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

// type large enough to hold all potential input/output values, as well as intermediate calculations
typedef int64_t working_type;

#define WORKING_MAX INT64_MAX

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

static working_type solve_case(working_type num_pots, working_type x_mult,
                               working_type y_mult) 
{
    const double quad_a = x_mult + y_mult;
    const double quad_b = -2 * y_mult * num_pots;
    const double quad_c = y_mult * num_pots * num_pots;
    const double parabola_min_x_coord = -quad_b / (2 * quad_a);
    const double parabola_min_y_coord = 
        solve_parabola(parabola_min_x_coord, quad_a, quad_b, quad_c);

    const working_type num_x_pots = (working_type)round(parabola_min_y_coord);
    return num_x_pots;
}

static void read_test_case() {
    working_type pots_to_buy;
    working_type x_cost;
    working_type y_cost;
    scanf("%lld %lld %lld", &pots_to_buy, &x_cost, &y_cost);
    const working_type soln = solve_case(pots_to_buy, x_cost, y_cost);
    printf("%lld\n", soln);
}

int main() {
    working_type num_problems;
    scanf("%lld", &num_problems);

    for(working_type i = 0; i < num_problems; ++i) {
        read_test_case();
    }
}

/*
(A \* X^2) + (B \* Y^2) = Q
(100000 \* X^2) + (91507 \* Y^2) = 241347217055747
(100000 \* X^2) = 241347217055747 - (91507 \* Y^2)

(A \* X^2) + (B \* Y^2) = Q
(100000 \* X^2) + (91507 \* Y^2) = Q
(100000 \* X^2) + (91507 \* (N - X)^2) = Q
(100000 \* X^2) + (91507 \* (71070 - X)^2) = Q



A parabola of the form y = ax^2 + bx + c has its minimum at min = c - b^2/4a
(100000 \* X^2) + (91507 \* (71070 - X)^2) = Q
100000 X^2 + (91507 * (X^2 - 142140 X + 5050944900)) = Q
100000 X^2 + 91507 X^2 - 13006804980 X + 462196814964300 = Q
191507 X^2 - 13006804980 X + 462196814964300 = Q

min = c - b^2/4a
min = 462196814964300 - ((-13006804980)^2) / (4 * 191507)
min = 462196814964300 - 169176975787752800400 / 766028
min = 462196814964300 - 169176975787752800400 / 766028


N = 5, A = 1, B = 2

X + Y = N
X + Y = 5
X = 5 - Y

// wrong
(A * X^2) + (B * Y^2) = Q
(1 * (5 - Y)^2) + (2 * Y^2) = Q
(5 - Y)^2 + 2 Y^2 = Q
25 - 10Y + 2Y^2 + 2 Y^2 = Q
25 - 10Y + 4Y^2 = Q
4Y^2 - 10Y + 25 = Q

min = c - b^2/4a
min = 25 - ((-10)^2) / (4 * 4)
min = 25 - 100 / 16
min = 25 - 25 / 4
min = 25 - 6.25
min = 18.75
min ~ 19

// right (Wolfram alpha)
3Y^2 - 10Y + 25 = Q

min x = -b / 2a
min x = -(-10) / 2(3)
min x = 10 / 6
min x = 5 / 3

f(5/3) = 3(5/3)^2 - 10(5/3) + 25 
3(25/9) - 50/3 + 25 = Q
25/3 - 50/3 + 25 = Q
-25/3 + 25 = Q
-25/3 + #(25)/3 = Q
(50/3) = Q
Q ~ 17

X >= 0
Y >= 0
X + Y = N

Minimize (A * X^2) + (B + Y^2)


Actual solution: 
We're given (A * X^2) + (B * Y^2) = Q, where Q is the cost
We also kow the Y = N - X
Q = (A * X^2) + (B * Y^2)
Q = (A * X^2) + (B * (N - X)^2)
Q = (A * X^2) + (B * (N^2 - 2NX + X^2))
Q = (A * X^2) + B*N^2 - 2BNX + BX^2
Q = (A + B)X^2 - 2BNX + B*N^2
a = A + B
b = 2 * B * N
c = B *N^2

min x value (real) = -b / 2a
= -2BN / 2(A + B)
= -BN / (A + B)

Solve for q
Round to nearest int

*/