
// gross, but should be good enough to get this to compile...
#define _ALLOW_COMPILER_AND_STL_VERSION_MISMATCH
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cmath>
#include <iostream>

// type large enough to hold all potential input/output values, for the purpose of printing and 
// scanning
using io_type = int64_t;

class quadratic_eq {
public:
    quadratic_eq(io_type num_pots, io_type x_mult, io_type y_mult) noexcept : 
        a_{ 1.0 * x_mult + y_mult },
        b_{ -2.0 * y_mult * num_pots },
        c_{ 1.0 * y_mult * num_pots * num_pots }
    {
        /* nothing */
    }

    [[nodiscard]] double minimum_value() const noexcept {
        return -b_ / (2.0 * a_);
    }

    [[nodiscard]] double at(double domain_value) const noexcept {
        const auto a_term = a_ * domain_value * domain_value;
        const auto b_term = b_ * domain_value;
        return a_term + b_term + c_;
    }

private:
    double a_;
    double b_;
    double c_;
};

[[nodiscard]] static quadratic_eq get_next_eq() noexcept {
    io_type pots_to_buy{};
    io_type x_cost{};
    io_type y_cost{};
    std::cin >> pots_to_buy >> x_cost >> y_cost;
    return { pots_to_buy, x_cost, y_cost };
}

static io_type solve_case(const quadratic_eq& case_eq) noexcept {
    const auto min = std::round(case_eq.minimum_value());
    const auto real_soln = std::round(case_eq.at(min));

    const io_type num_x_pots = static_cast<io_type>(real_soln);
    return num_x_pots;
}

static void read_test_case() {
    const auto eq = get_next_eq();
    const auto soln = solve_case(eq);
    std::cout << soln << "\n";
}

int main() {
    io_type num_problems{};
    std::cin >> num_problems;

    for (io_type i = 0; i < num_problems; ++i) {
        read_test_case();
    }
}
