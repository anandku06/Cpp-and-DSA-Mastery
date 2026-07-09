// 3756. Concatenate Non-Zero Digits and Multiply by Sum II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

// For each queries[i], extract the substring s[li..ri]. Then, perform the following:

// Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
// Let sum be the sum of digits in x. The answer is x * sum.
// Return an array of integers answer where answer[i] is the answer to the ith query.

// Since the answers may be very large, return them modulo 109 + 7.

// Example 1:

// Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]

// Output: [12340, 4, 9]

// Explanation:

// s[0..7] = "10203004"
// x = 1234
// sum = 1 + 2 + 3 + 4 = 10
// Therefore, answer is 1234 * 10 = 12340.
// s[1..3] = "020"
// x = 2
// sum = 2
// Therefore, the answer is 2 * 2 = 4.
// s[4..6] = "300"
// x = 3
// sum = 3
// Therefore, the answer is 3 * 3 = 9.
// Example 2:

// Input: s = "1000", queries = [[0,3],[1,1]]

// Output: [1, 0]

// Explanation:

// s[0..3] = "1000"
// x = 1
// sum = 1
// Therefore, the answer is 1 * 1 = 1.
// s[1..1] = "0"
// x = 0
// sum = 0
// Therefore, the answer is 0 * 0 = 0.
// Example 3:

// Input: s = "9876543210", queries = [[0,9]]

// Output: [444444137]

// Explanation:

// s[0..9] = "9876543210"
// x = 987654321
// sum = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
// Therefore, the answer is 987654321 * 45 = 44444444445.
// We return 44444444445 modulo (109 + 7) = 444444137.

// Constraints:

// 1 <= m == s.length <= 105
// s consists of digits only.
// 1 <= queries.length <= 105
// queries[i] = [li, ri]
// 0 <= li <= ri < m

// approach: We can iterate through each query and extract the substring from s. Then, we can iterate through the substring and concatenate all the non-zero digits to form the integer x. We can also calculate the sum of the digits in x. Finally, we can calculate the answer for each query as x * sum and return the results modulo 10^9 + 7.

#include <bits/stdc++.h>
using namespace std;

class TLE_Solution
{
public:
    int MOD = 1e9 + 7;    // define the modulo value
    typedef long long ll; // define a long long type for large integer calculations

    vector<int> concatenateNonZeroDigits(string s, vector<vector<int>> &queries)
    {
        vector<int> ans; // vector to store the answers for each query

        for (auto &q : queries)
        {
            int l = q[0], r = q[1];              // extract the left and right indices from the query
            string sub = s.substr(l, r - l + 1); // extract the substring from s

            ll x = 0;   // initialize x to 0
            ll sum = 0; // initialize sum to 0

            for (char c : sub)
            {
                if (c != '0') // if the character is not '0'
                {
                    x = (x * 10 + (c - '0')) % MOD; // concatenate the digit to x and take modulo
                    sum += (c - '0');               // add the digit to sum
                }
            }

            ll result = (x * sum) % MOD; // calculate the result for the current query
            ans.push_back(result);       // add the result to the answer vector
        }

        return ans; // return the answer vector
    }
};

// approach: We can precompute the prefix sums and prefix concatenated values for the string s. Then, for each query, we can use the precomputed values to calculate x and sum in O(1) time. This will reduce the overall time complexity to O(n + q), where n is the length of the string and q is the number of queries.

class Optimal_Solution
{
public:
    int MOD = 1e9 + 7;    // define the modulo value
    typedef long long ll; // define a long long type for large integer calculations

    vector<int> concatenateNonZeroDigits(string s, vector<vector<int>> &queries)
    {
        int n = s.length();

        vector<int> nonZeroCount(n, 0); // non-zero digits count in s[0..i]
        vector<ll> numberUpTo(n, 0);    // number formed from non-zero digits in s[0..i]
        vector<ll> digitSumUpTo(n, 0);  // digit sum of s[0..i]
        vector<ll> pow10(n + 1, 0);     // 10^i

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        numberUpTo[0] = s[0] - '0';
        digitSumUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; i++)
        {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
        }

        for (int i = 1; i < n; i++)
        {
            int digit = s[i] - '0';
            if (digit != 0)
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % MOD;
            else
                numberUpTo[i] = numberUpTo[i - 1];
        }

        for (int i = 1; i < n; i++)
        {
            digitSumUpTo[i] = digitSumUpTo[i - 1] + (s[i] - '0');
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            int startCount = (l == 0) ? 0 : nonZeroCount[l - 1];
            ll numBefore = (l == 0) ? 0 : numberUpTo[l - 1];

            int endCount = nonZeroCount[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0)
            {
                result[i] = 0;
                continue;
            }

            ll x = (numberUpTo[r] - (numBefore * pow10[subStrLen] % MOD) + MOD) % MOD;
            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int)((x * sum) % MOD);
        }

        return result;
    }
};