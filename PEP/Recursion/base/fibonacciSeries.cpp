// using a unordered set to store fibonacci sequence; this reduces the unneccessary calling

#include <bits/stdc++.h>
using namespace std;

// dynamic programming approach to fibonacci sequence (memoization)
long int fibonacciSequenceMemoization(int n, unordered_map<int, long int> &memo)
{
    if (n == 0 || n == 1)
        return n;

    if (memo.find(n) != memo.end())
        return memo[n];

    memo[n] = fibonacciSequenceMemoization(n - 1, memo) + fibonacciSequenceMemoization(n - 2, memo);
    return memo[n];
}

// dynamic programming approach to fibonacci sequence (tabulation)
long int fibonacciSequenceDP(int n)
{
    if (n == 0 || n == 1)
        return n;

    vector<long int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

// iterative approach to fibonacci sequence
long int fibonacciSequenceIterative(int n)
{
    if (n == 0 || n == 1)
        return n;

    long int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

// recursive approach to fibonacci sequence
long int fibonacciSequenceRecursive(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fibonacciSequenceRecursive(n - 2) + fibonacciSequenceRecursive(n - 1);
}