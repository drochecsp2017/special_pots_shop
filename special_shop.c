
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// type large enough to hold all potential input/output values, as well as intermediate calculations
typedef int64_t working_type;

enum {
    working_type_max = INT64_MAX
};

static working_type pot_price(working_type count, working_type multiplier) {
    return multiplier * count * count;
}

static working_type solve_case(working_type num_pots, working_type x_cost, working_type y_cost) {
    working_type final_cost = working_type_max;
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
    working_type soln = solve_case(pots_to_buy, x_cost, y_cost);
    printf("%lld\n", soln);
}

int main() {
    working_type num_problems;
    scanf("%lld", &num_problems);

    for(working_type i = 0; i < num_problems; ++i) {
        read_test_case();
    }
}