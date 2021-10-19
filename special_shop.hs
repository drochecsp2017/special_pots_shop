
module Main where

import System.Console.Haskeline.IO ()

data Equation = Parabola Float Float Float 

calcEquation :: Float -> Float -> Float -> Equation
calcEquation n a b = 
    let factA = a + b
        factB = -2.0 * b * n
        factC = b * n * n
    in Parabola factA factB factC

findEqMin :: Equation -> Integer  
findEqMin (Parabola a b _) = 
    let result = -1.0 * b / (2 * a)
    in round result 

solveEqAt :: Equation -> Float -> Integer
solveEqAt (Parabola a b c) xCoord = 
    let factA = a * xCoord * xCoord
        factB = b * xCoord
        factC = c
    in round (factA + factB + factC)

solveTestCase :: Int -> Int -> Int -> Integer
solveTestCase numPots aMult bMult =
    let fN = (fromIntegral numPots :: Float)
        fA = (fromIntegral aMult :: Float)
        fB = (fromIntegral bMult :: Float)
        eq = calcEquation fN fA fB
    in solveEqAt eq (fromIntegral (findEqMin eq) :: Float)


runTests :: [IO (Int, Int, Int)] -> IO()
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

readInts :: IO [Int]
readInts = fmap (map read . words) getLine

parseTestCase :: IO (Int, Int, Int)
parseTestCase = do
    input <- readInts
    let numPots = head input
    let aMult = input !! 1
    let bMult = input !! 2
    return (numPots, aMult, bMult)

main :: IO ()
main = do
    print "hi"
    numTests <- parseNumTests
    print numTests
    let inputs = replicate numTests parseTestCase
    runTests inputs