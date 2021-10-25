
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

    fn calcEquation(args: Input) -> Equation {
        let numPots = args.0 as Float;
        let aMult = args.1 as Float;
        let bMult = args.2 as Float;
        return Equation {
            coeff_a: aMult as Float + bMult,
            coeff_b: -2.0 * (bMult * numPots) as Float,
            coeff_c: bMult * numPots.powi(2) as Float,
        };
    }

    fn findEqMin(&self) -> Float {
        let numerator = -1.0 * self.coeff_b;
        let denominator = 2.0 * self.coeff_a;
        let result = numerator / denominator;
        return result;
    }

    fn solveAt(&self, x: Float) -> Float {
        let termA = self.coeff_a.powi(2) * x;
        let termB = self.coeff_b * x;
        let termC = self.coeff_c;
        return termA + termB + termC;
    }

} // impl Equation

fn solveCase(args: Input) -> Integer {
    let eq = Equation::calcEquation(args);
    let min = eq.findEqMin();
    let soln = eq.solveAt(min.round());
    return soln.round() as Integer;
}

fn parseCase(buffer: &mut String) -> Option<Input> {
    match io::stdin().read_line(buffer) {
        Ok(_n) => {
            let trimmed_buffer = buffer.trim();
            let vec: Vec<&str> = trimmed_buffer.split(" ").collect();
    
            let numPots = vec[0].parse::<Integer>().unwrap();
            let aMult = vec[1].parse::<Integer>().unwrap();
            let bMult = vec[2].parse::<Integer>().unwrap();
            return Some((numPots, aMult, bMult))
        }

        Err(_error) => return None,
    }
}

fn runCase(buffer: &mut String) {
    match parseCase(buffer) {
        Some(args) => {
            let soln = solveCase(args);
            println!("{}", soln);
        }

        None => (),
    }
    buffer.clear();
}


fn getNumCases(buffer: &mut String) -> i32 {
    io::stdin().read_line(buffer).expect("could not read line");
    let num_cases = buffer.trim().parse::<i32>().unwrap();
    buffer.clear();
    return num_cases;
}

fn main() {
    let mut buffer = String::new();
    let numCases = getNumCases(&mut buffer);

    for _ in 0..numCases {
        runCase(&mut buffer);
    }
}

