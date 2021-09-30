
# TODO test

class quadratic_eq:
    def __init__(self, num_pots: int, x_mult: int, y_mult: int) -> None:
        self.a_ = float(x_mult) + float(y_mult)
        self.b_ = -2.0 * y_mult * num_pots
        self.c_ = float(y_mult) * (num_pots ** 2)

    def min_point(self) -> float:
        numerator = -self.b_
        denominator = 2.0 * self.a_
        return numerator / denominator

    def solve_at(self, x_value: float) -> float:
        a_factor = self.a_ * (x_value ** 2)
        b_factor = self.b_ * x_value
        return a_factor + b_factor + self.c_



def solve_case(eq: quadratic_eq) -> int:
    min_val = eq.min_point()
    min_val = round(min_val)
    real_soln = eq.solve_at(min_val)
    return round(real_soln)

def read_case():
    test_case_line = input()

    inputs = []
    for s in test_case_line.split(' '):
        inputs.append(int(s))

    if (len(inputs) != 3):
        raise RuntimeError("I don't understand how input works")

    eq = quadratic_eq(*inputs)
    soln = solve_case(eq)
    print(soln)

def main():
    num_ranges = int(input())
    for _ in range(num_ranges):
        read_case()


if __name__ == '__main__':
    main()