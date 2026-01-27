// using a unordered set to store fibonacci sequence; this reduces the unneccessary calling

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo; // to avoid repeated calling of the function

long int fibonacciSequence(int n) {
    if(n == 0 || n == 1) return n;

    if(memo.find(n) != memo.end()) {
        return memo[n];
    }

    memo[n] = fibonacciSequence(n - 2) + fibonacciSequence(n - 1); // storing the sequence to use if needed

    return memo[n];
}

int main()
{
    
    return 0;
}