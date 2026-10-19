/*
Binary Exponentiation

- It is a method to compute a^b efficiently in O(log b) time.
- The idea is to use the property of exponents:
  - If b is even, a^b = (a^(b/2))^2
  - If b is odd, a^b = a * a^(b-1)

- Example:
  - To compute 3^13:
    - 3^13 = 3 * 3^12
    - 3^12 = (3^6)^2
    - 3^6 = (3^3)^2
    - 3^3 = 3 * 3^2
    - 3^2 = (3^1)^2
    - 3^1 = 3
    - 3^0 = 1
    - Therefore, 3^13 = 3 * (3^6)^2 = 3 * (3^3)^4 = 3 * (3 * 3^2)^4 = 3 * (3 * (3^1)^2)^4 = 3 * (3 * 3)^4 = 3 * 9^4 = 3 * 6561 = 19683
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long binaryExponentiation(long long a, long long b)
    {
        long long res = 1; // Initialize result
        while (b > 0)
        {
            if (b % 2 == 1) // If b is odd, multiply a with result
                res = (res * a);
            a = (a * a); // Square the base
            b /= 2;      // Divide b by 2
        }
        return res;
    }
};