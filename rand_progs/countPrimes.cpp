// 204. Count Primes
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0

// Constraints:

// 0 <= n <= 5 * 106

// approach: Using Sieve of Eratosthenes
// Intuition
// The problem can be solved using the Sieve of Eratosthenes algorithm. We can create a boolean array isPrime of size n, initialized to true. We will then iterate through the array and for each prime number, we will mark all its multiples as non-prime. Finally, we will count the number of true values in the isPrime array, which represents the number of prime numbers less than n.

/*
Sieve of Eratosthenes is an efficient algorithm to find all prime numbers up to a given limit. The basic idea is to iteratively mark the multiples of each prime number starting from 2. The numbers which remain unmarked after processing all primes are the prime numbers.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0; // There are no prime numbers less than 2

        vector<bool> isPrime(n, true);   // Create a boolean array to mark prime numbers
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false; // Mark all multiples of i as non-prime
                }
            }
        }

        return count(isPrime.begin(), isPrime.end(), true); // Count the number of true values in the isPrime array
    }
};