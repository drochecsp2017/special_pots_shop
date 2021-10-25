
// Javascript using Node

function makeEquation(numPots, aMult, bMult) {
    return {
        coeffA: aMult + bMult,
        coeffB: -2 * bMult * numPots,
        coeffC: bMult * Math.pow(numPots, 2)
    };
}

function findEquationMin(eq) {
    const numerator = -eq.coeffB;
    const denominator = 2 * eq.coeffA;
    return numerator / denominator;
}

function solveEquationAt(eq, xCoord) {
    const aTerm = eq.coeffA * Math.pow(xCoord, 2);
    const bTerm = eq.coeffB * xCoord;
    const cTerm = eq.coeffC;
    return aTerm + bTerm + cTerm;
}

function solveCase(numPots, aMult, bMult) {
    const eq = makeEquation(numPots, aMult, bMult);
    const min = findEquationMin(eq);
    const soln = solveEquationAt(eq, Math.round(min));
    return Math.round(soln);
}

function parseCaseLine(line) {
    const range_strings = line.split(' ');
    const numPots = parseInt(range_strings[0], 10);
    const aMult = parseInt(range_strings[1], 10);
    const bMult = parseInt(range_strings[2], 10);
    return [ numPots, aMult, bMult ];
}

function runCase(line) {
    const [numPots, aMult, bMult] = parseCaseLine(line);
    const soln = solveCase(numPots, aMult, bMult);
    console.log(soln);
}

function* main() {
    const initialLine = yield;
    const num_lines = parseInt(initialLine, 10);
    
    for(let i = 0; i < num_lines; ++i) {
        let inputLine = yield;
        runCase(inputLine);
    }
}

// import Node's readline module
var readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});
process.stdin.resume();
process.stdin.setEncoding("utf-8");

const mainLoop = main();
mainLoop.next();
rl.on('line', line => mainLoop.next(line));
