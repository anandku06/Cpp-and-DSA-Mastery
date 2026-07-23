// 3513. Number of Unique XOR Triplets I
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums of length n, where nums is a permutation of the numbers in the range [1, n].

// A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

// Return the number of unique XOR triplet values from all possible triplets (i, j, k).

// Example 1:

// Input: nums = [1,2]

// Output: 2

// Explanation:

// The possible XOR triplet values are:

// (0, 0, 0) → 1 XOR 1 XOR 1 = 1
// (0, 0, 1) → 1 XOR 1 XOR 2 = 2
// (0, 1, 1) → 1 XOR 2 XOR 2 = 1
// (1, 1, 1) → 2 XOR 2 XOR 2 = 2
// The unique XOR values are {1, 2}, so the output is 2.

// Example 2:

// Input: nums = [3,1,2]

// Output: 4

// Explanation:

// The possible XOR triplet values include:

// (0, 0, 0) → 3 XOR 3 XOR 3 = 3
// (0, 0, 1) → 3 XOR 3 XOR 1 = 1
// (0, 0, 2) → 3 XOR 3 XOR 2 = 2
// (0, 1, 2) → 3 XOR 1 XOR 2 = 0
// The unique XOR values are {0, 1, 2, 3}, so the output is 4.

// Constraints:

// 1 <= n == nums.length <= 105
// 1 <= nums[i] <= n
// nums is a permutation of integers from 1 to n.

// Approach: Using Set to store unique XOR values
// Intuition
// We can use a set to store all unique XOR triplet values. For each triplet (i, j, k), we calculate the XOR and insert it into the set. Finally, we return the size of the set.
// Time Complexity: O(n^3) in the worst case, where n is the length of the input array nums. This is because we are iterating through all possible triplets (i, j, k) in the array.

// Optimization
// Bit Manipulation: We can optimize the solution by using bit manipulation. Since nums is a permutation of numbers from 1 to n, we can use the property of XOR to reduce the number of triplets we need to consider. Specifically, we can use the fact that for any three numbers a, b, and c, the XOR of these three numbers is equal to the XOR of the first two numbers XORed with the third number. This allows us to reduce the number of triplets we need to consider from O(n^3) to O(n^2).

/*
Notice the clear pattern depending on n:
    Case n = 1:
    Only value is 1 ^ 1 ^ 1 = 1.
    Output = 1.

    Case n = 2:
    Possible XORs:1 ^ 1 ^ 1 = 1 | 1 ^ 1 ^ 2 = 2 | 1 ^ 2 ^ 2 = 1 | 2 ^ 2 ^ 2 = 2
    Reachable set: {1, 2}.
    Output = 2.

    Case n >= 3:
    Let p be the position of the most significant bit (MSB) of n.
    Specifically, if 2^k <= n < 2^{k+1}:
        Since n >= 3, any bit below the MSB can be flipped on or off using elements in {1, ..., n}.
        In fact, three numbers x, y, z <= n can span all integers in the full bit-mask range [0, 2^{k+1} - 1].
        Why 2^{k+1}? Because 2^k <= n, the highest bit present in the set is 2^k. XORing three elements can yield any number up to 2^{k+1} - 1.
        Therefore, for any n >= 3:
            The number of unique XOR values is simply 2^{k+1}, where 2^k is the highest power of 2 less than or equal to n.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return n; // For n = 1 or n = 2, the number of unique XOR triplet values is equal to n.

        // Find the position of the most significant bit (MSB) of n
        int msbPos = 32 - __builtin_clz(n); // __builtin_clz counts leading zeros in the binary representation of n
        return 1 << msbPos;                 // Return 2^(msbPos), which is the number of unique XOR triplet values for n >= 3.
    }
};