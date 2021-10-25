
use std::io;

// define "default" sized numerical types that will be alrge enough to handle all inputs
type Integer = i64;
type Float = f64;
type Input = (Integer, Integer, Integer);

struct Equation {
    coeff_a: Float,
    coeff_b: Float,
    coeff_c: Float,
}

impl Equation {

    fn calc_equation(args: Input) -> Equation {
        let num_pots = args.0 as Float;
        let a_mult = args.1 as Float;
        let b_mult = args.2 as Float;
        return Equation {
            coeff_a: a_mult + b_mult,
            coeff_b: -2.0 * (b_mult * num_pots),
            coeff_c: b_mult * num_pots.powi(2),
        };
    }

    fn find_eq_min(&self) -> Float {
        let numerator = -1.0 * self.coeff_b;
        let denominator = 2.0 * self.coeff_a;
        let result = numerator / denominator;
        return result;
    }

    fn solve_at(&self, x: Float) -> Float {
        let term_a = self.coeff_a.powi(2) * x;
        let term_b = self.coeff_b * x;
        let term_c = self.coeff_c;
        return term_a + term_b + term_c;
    }

} // impl Equation

fn solve_case(args: Input) -> Integer {
    let eq = Equation::calc_equation(args);
    let min = eq.find_eq_min();
    let soln = eq.solve_at(min.round());
    return soln.round() as Integer;
}

fn parse_case(buffer: &mut String) -> Option<Input> {
    match io::stdin().read_line(buffer) {
        Ok(_n) => {
            let trimmed_buffer = buffer.trim();
            let vec: Vec<&str> = trimmed_buffer.split(" ").collect();
    
            let num_pots = vec[0].parse::<Integer>().unwrap();
            let a_mult = vec[1].parse::<Integer>().unwrap();
            let b_mult = vec[2].parse::<Integer>().unwrap();
            return Some((num_pots, a_mult, b_mult))
        }

        Err(_error) => return None,
    }
}

fn run_case(buffer: &mut String) {
    match parse_case(buffer) {
        Some(args) => {
            let soln = solve_case(args);
            println!("{}", soln);
        }

        None => (),
    }
    buffer.clear();
}


fn get_num_cases(buffer: &mut String) -> i32 {
    io::stdin().read_line(buffer).expect("could not read line");
    let num_cases = buffer.trim().parse::<i32>().unwrap();
    buffer.clear();
    return num_cases;
}

fn main() {
    let mut buffer = String::new();
    let num_cases = get_num_cases(&mut buffer);

    for _ in 0..num_cases {
        run_case(&mut buffer);
    }
}

