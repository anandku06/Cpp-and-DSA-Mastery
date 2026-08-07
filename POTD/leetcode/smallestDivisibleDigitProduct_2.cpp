// 3348. Smallest Divisible Digit Product II
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string num which represents a positive integer, and an integer t.

// A number is called zero-free if none of its digits are 0.

// Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".

// Example 1:

// Input: num = "1234", t = 256

// Output: "1488"

// Explanation:

// The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.

// Example 2:

// Input: num = "12355", t = 50

// Output: "12355"

// Explanation:

// 12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.

// Example 3:

// Input: num = "11111", t = 26

// Output: "-1"

// Explanation:

// No number greater than 11111 has the product of its digits divisible by 26.

// Constraints:

// 2 <= num.length <= 2 * 105
// num consists only of digits in the range ['0', '9'].
// num does not contain leading zeros.
// 1 <= t <= 1014

// approach: Brute Force
// Intuition
// The problem can be solved using brute force. We can start from the given number num and keep incrementing it until we find a number that is zero-free and has the product of its digits divisible by t. We can check if a number is zero-free by checking if it contains any digit 0. We can check if the product of its digits is divisible by t by calculating the product of its digits and checking if it is divisible by t. If we find such a number, we return it as a string. If we reach a certain limit (for example, 10^14) and do not find such a number, we return "-1".
// Time Complexity: O(n * m), where n is the number of digits in num and m is the number of digits in the product of the digits of the number we are checking. In the worst case, we may have to check all numbers from num to 10^14, which can take a long time.

#include <bits/stdc++.h>
using namespace std;

class Brute_Solution
{
public:
    string smallestDivisibleDigitProduct(string num, long long t)
    {
        long long n = stoll(num); // convert the string to a long long integer
        while (n <= 1e14)
        {                            // loop until we reach the limit of 10^14
            string s = to_string(n); // convert the number back to a string
            if (s.find('0') == string::npos)
            {                          // check if the number is zero-free
                long long product = 1; // initialize the product of digits
                for (char c : s)
                {                         // iterate through each digit
                    product *= (c - '0'); // calculate the product of digits
                }
                if (product % t == 0)
                {             // check if the product is divisible by t
                    return s; // return the number as a string if it satisfies the conditions
                }
            }
            n++; // increment the number and check the next one
        }
        return "-1"; // return "-1" if no such number exists within the limit
    }
};

// approach: Optimized (Prime Factorization and Backtracking)
// Intuition

class Optimized_Solution
{
public:
    typedef long long ll;

    string freeSlotsFiller(ll required, int length)
    {
        string str;

        for (int digit = 9; digit >= 2; digit--)
        {
            while (required % digit == 0)
            {
                str.push_back(digit + '0');
                required /= digit;
            }
        }

        while (str.length() < length)
        {
            str.push_back('1');
        }

        reverse(begin(str), end(str));

        return str;
    }

    string smallestNumber(string num, long long t)
    {
        int n = num.length(); // get the length of the input string num

        // Check if t has any prime factors other than 2, 3, 5, or 7
        ll temp = t;
        for (int primeFact : {2, 3, 5, 7})
        {
            while (temp % primeFact == 0)
            {
                temp /= primeFact;
            }
        }

        // If t has any prime factors other than 2, 3, 5, or 7, return "-1" as it is impossible to form a number with the product of its digits divisible by t
        if (temp != 1)
        {
            return "-1";
        }

        // Precompute remainingFactor[i] = if we take i digits of num in my result, what factor remaining for t
        vector<ll> remainingFactor(n + 1, t);
        //"123045"

        // remainingFactor[0] = t, remainingFactor[1] = t / gcd(t, 1), remainingFactor[2] = t / gcd(t, 1 * 2), remainingFactor[3] = t / gcd(t, 1 * 2 * 3), remainingFactor[4] = t / gcd(t, 1 * 2 * 3 * 0) = t, remainingFactor[5] = t / gcd(t, 1 * 2 * 3 * 0 * 4) = t, remainingFactor[6] = t / gcd(t, 1 * 2 * 3 * 0 * 4 * 5) = t
        for (int i = 0; i < n; i++)
        {
            int digit = num[i] - '0';

            if (digit == 0)
            {
                break;
            }

            remainingFactor[i + 1] = remainingFactor[i] / __gcd(remainingFactor[i], (ll)digit);
        }

        // If remainingFactor[n] == 1, it means that the product of all digits in num is divisible by t, so we can return num as the result
        if (remainingFactor[n] == 1)
        {
            return num;
        }

        // If remainingFactor[n] != 1, we need to find the smallest number greater than or equal to num such that the product of its digits is divisible by t
        int zeroPos = num.find('0');
        int zeroIdx = n - 1;
        if (zeroPos != -1)
        {
            zeroIdx = zeroPos;
        }

        // Iterate from the last digit to the first digit
        for (int i = zeroIdx; i >= 0; i--)
        {
            ll required = remainingFactor[i]; // get the remaining factor for t after taking the first i digits of num
            int freeSlots = n - 1 - i;        // calculate the number of free slots available for filling the remaining digits

            for (int digit = (num[i] - '0') + 1; digit <= 9; digit++) // iterate through the digits greater than the current digit in num
            {
                ll furtherRequired = required / __gcd(required, digit);              // calculate the further required factor for t after taking the current digit
                string requiredNumber = freeSlotsFiller(furtherRequired, freeSlots); // fill the remaining free slots with the smallest possible digits such that the product of the digits is divisible by t

                if (requiredNumber.length() == freeSlots) // check if the length of the required number is equal to the number of free slots
                {
                    return num.substr(0, i) + char(digit + '0') + requiredNumber; // return the smallest number greater than or equal to num such that the product of its digits is divisible by t
                }
            }
        }

        return freeSlotsFiller(t, n + 1); // num = "11", t = 2^15
    }
};

/*
       - Now we need to find the smallest number greater than or equal to num such that the product of its digits is divisible by t
       - We will iterate from the last digit of num to the first digit, and for each digit, we will try to replace it with a larger digit and fill the remaining digits with the smallest possible digits such that the product of the digits is divisible by t
       - Find the position of the first '0' in num, if any, and set zeroIdx to that position. If there is no '0', set zeroIdx to n - 1 (the last index of num)
       - why we are doing this because if we have a '0' in num, we cannot use any digits after that position to form a valid number, so we can only consider digits before that position, and we will try to replace the digit at that position with a larger digit and fill the remaining digits with the smallest possible digits such that the product of the digits is divisible by t

       - For example, if num = "123045" and t = 6, we can only consider the digits "123" and try to replace the digit '3' with a larger digit and fill the remaining digits with the smallest possible digits such that the product of the digits is divisible by t
       - If we replace '3' with '4', we get "124", and the product of the digits is 1 * 2 * 4 = 8, which is not divisible by 6, so we cannot use this number
       - If we replace '3' with '5', we get "125", and the product of the digits is 1 * 2 * 5 = 10, which is not divisible by 6, so we cannot use this number
       - If we replace '3' with '6', we get "126", and the product of the digits is 1 * 2 * 6 = 12, which is divisible by 6, so we can use this number
       - If we replace '3' with '7', we get "127", and the product of the digits is 1 * 2 * 7 = 14, which is not divisible by 6, so we cannot use this number
       - If we replace '3' with '8', we get "128", and the product of the digits is 1 * 2 * 8 = 16, which is not divisible by 6, so we cannot use this number
       - If we replace '3' with '9', we get "129", and the product of the digits is 1 * 2 * 9 = 18, which is divisible by 6, so we can use this number
       - Therefore, the smallest number greater than or equal to num such that the product of its digits is divisible by t is "126", and we can return this number as the result
       - what about the remaining digits after the position of the first '0' in num? We can fill them with the smallest possible digits such that the product of the digits is divisible by t, which is done by the freeSlotsFiller function
*/