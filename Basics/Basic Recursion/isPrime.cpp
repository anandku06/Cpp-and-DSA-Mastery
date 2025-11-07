// Given an integer num, return true if it is prime otherwise false.



// A prime number is a number that is divisible only by 1 and itself.


// Examples:
// Input : num = 5

// Output : true

// Explanation : The factors of 5 are 1 and 5 only.

// So it satisfies the prime number condition.

// Input : num = 15

// Output : false

// Explanation : The factors of 15 are 1, 3, 5, 15 only.

// As the number has factors other than 1 and itself, So it is not a prime number.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPrime(int num) {
     // 0 and 1 are not prime numbers
        if (num <= 1) {
            return false;
        }
       // Call the helper function to check for primality
        return prime(num, 2); 
    }

private:
    bool prime(int num, int x) {
    // Base case: x > sqrt(num), so the number is prime
        if (x > sqrt(num)) {
            return true; 
        }

        if (num % x == 0) {
        // Found a divisor, so the number is not prime
            return false; 
        }
       // Recursive call with the next divisor
        return prime(num, x + 1); 
    }
};

// Main method
int main() {
    Solution solution;
    int num = 7; 
    bool result = solution.checkPrime(num); 
    cout << (result ? "Prime" : "Not Prime") << endl; 
    return 0;
}