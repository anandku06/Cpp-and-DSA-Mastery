// Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.


// Examples:
// Input : N = 4

// Output : 10

// Explanation : first four natural numbers are 1, 2, 3, 4.

// Sum is 1 + 2 + 3 + 4 => 10.

// Input : N = 2

// Output : 3

// Explanation : first two natural numbers are 1, 2.

// Sum is 1 + 2 => 3.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int NnumbersSum(int N) {
        // Base case: if N is 0, return 0
        if (N == 0) return 0;
        // Recursive case: add N to the sum of N-1
        return N + NnumbersSum(N - 1);
    }
};

int main() {
    Solution solution;
    int N = 10; // Example input
    cout << "Sum of first " << N << " numbers is " << solution.NnumbersSum(N) << endl;
    return 0;
}
