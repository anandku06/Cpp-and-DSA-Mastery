/*
This program calculates the nth Fibonacci number using dynamic programming approach. It uses an array to store previously computed Fibonacci numbers to avoid redundant calculations, thus improving efficiency compared to the naive recursive approach.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursive function
    int fibonacciRecursive(int n)
    {
        if (n <= 1)
            return n;                                                 // base case: return n if it is 0 or 1
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2); // recursive case: sum of the two preceding Fibonacci numbers
    }

    // iterative function
    int fibonacciIterative(int n)
    {
        int a = 0, b = 1, c; // initialize the first two Fibonacci numbers
        if (n == 0)
            return a; // return 0 if n is 0

        for (int i = 2; i <= n; i++)
        {
            c = a + b; // calculate the next Fibonacci number
            a = b;     // update a to the previous Fibonacci number
            b = c;     // update b to the current Fibonacci number
        }

        return b; // return the nth Fibonacci number
    }

    // dynamic programming function (tabulation)
    int fibonacciDP(int n)
    {
        if (n <= 1)
            return n; // base case: return n if it is 0 or 1

        vector<int> fib(n + 1); // create an array to store Fibonacci numbers up to n
        fib[0] = 0;             // initialize the first Fibonacci number
        fib[1] = 1;             // initialize the second Fibonacci number

        for (int i = 2; i <= n; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2]; // fill the array with Fibonacci numbers using the recurrence relation
        }

        return fib[n]; // return the nth Fibonacci number
    }

    // dynamic programming function (memoization)
    int fibonacciMemoization(int n, vector<int> &memo)
    {
        if (n <= 1)
            return n; // base case: return n if it is 0 or 1

        if (memo[n] != -1)
            return memo[n]; // return the stored value if it has already been computed

        memo[n] = fibonacciMemoization(n - 1, memo) + fibonacciMemoization(n - 2, memo); // compute and store the value

        return memo[n]; // return the nth Fibonacci number
    }

    int fib(int n)
    {
        // Uncomment the desired method to calculate Fibonacci number

        // return fibonacciRecursive(n); // using recursion
        // return fibonacciIterative(n); // using iteration
        // return fibonacciDP(n);        // using dynamic programming (tabulation)

        vector<int> memo(n + 1, -1);          // create a memoization array initialized to -1
        return fibonacciMemoization(n, memo); // using dynamic programming (memoization)
    }
};