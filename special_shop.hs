
module Main where


data Equation = Parabola Double Double Double 


calcEquation :: Double -> Double -> Double -> Equation
calcEquation n a b = 
    let factA = a + b
        factB = -2.0 * b * n
        factC = b * n * n
    in Parabola factA factB factC

findEqMin :: Equation -> Integer  
findEqMin (Parabola a b _) = 
    let result = -1.0 * b / (2 * a)
    in round result

solveEqAt :: Equation -> Double -> Integer
solveEqAt (Parabola a b c) xCoord = 
    let factA = a * xCoord * xCoord
        factB = b * xCoord
        factC = c
    in round (factA + factB + factC)

solveTestCase :: Integer -> Integer -> Integer -> Integer
solveTestCase numPots aMult bMult =
    let fN = (fromIntegral numPots :: Double)
        fA = (fromIntegral aMult :: Double)
        fB = (fromIntegral bMult :: Double)
        eq = calcEquation fN fA fB
    in solveEqAt eq (fromIntegral (findEqMin eq) :: Double)

runTests :: [IO (Integer, Integer, Integer)] -> IO()
runTests (first:rest) = do
    (n, a, b) <- first
    let soln = solveTestCase n a b
    print soln
    runTests rest
runTests [] = return()

parseNumTests :: IO Int
parseNumTests = do
    line <- getLine
    let numTests = read line :: Int
    return numTests

readInts :: IO [Integer]
readInts = fmap (map read . words) getLine

parseTestCase :: IO (Integer, Integer, Integer)
parseTestCase = do
    input <- readInts
    let numPots = head input
    let aMult = input !! 1
    let bMult = input !! 2
    return (numPots, aMult, bMult)

main :: IO ()
main = do
    numTests <- parseNumTests
    let inputs = replicate numTests parseTestCase
    runTests inputs