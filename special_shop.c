
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// type large enough to hold all potential input/output values, as well as intermediate calculations
typedef int64_t working_type;

#define WORKING_MAX INT64_MAX

static working_type pot_price(working_type count, working_type multiplier) {
    return multiplier * count * count;
}

static working_type solve_case(working_type num_pots, working_type x_cost, working_type y_cost) {
    working_type final_cost = WORKING_MAX;
    for(working_type i = 0; i <= num_pots; ++i) {
        const working_type x_price = pot_price(i, x_cost);
        const working_type y_price = pot_price(num_pots - i, y_cost);

        const working_type current_price = y_price + x_price;
        if (current_price < final_cost) {
            final_cost = current_price;
        }
    }

    return final_cost;
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

4Y^2 - 10Y + 25 = Q
4(19)^2 - 190 + 25 = Q
1444 - 165 = Q
1444 - 165 = Q
1279 = Q


X >= 0
Y >= 0
X + Y = N

Minimize (A * X^2) + (B + Y^2)

*/