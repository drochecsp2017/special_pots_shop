
# Explanation

This directory contains a number of implementations of a medium-level HackerEath problem in 
multiple languages. It was meant to provide me some basic experience implementing a simple task 
with a multitude of tools. 

# The prompt

Creatnx now wants to decorate his house by flower pots. He plans to buy exactly N ones. He can only
buy them from Triracle's shop. There are only two kind of flower pots available in that shop. The 
shop is very strange. If you buy A flower pots of kind 1 then you must pay A \* X^2 and B \* Y^2 if 
you buy B flower pots of kind 2. Please help Creatnx buys exactly N flower pots that minimizes 
money he pays.

It's essentially a system of equations:
* X + Y = N
* (A \* X^2) + (B \* Y^2) = 0 (or whatever the min is) 

## Input Format

The first line contains a integer  denoting the number of test cases.

Each of test case is described in a single line containing three space-separated integers .

## Output Format

For each test case, print a single line containing the answer.