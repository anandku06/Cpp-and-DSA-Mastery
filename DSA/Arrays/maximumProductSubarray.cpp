// 152. Maximum Product Subarray
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that element.

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

class Brute_Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        int res = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int prod = 1;

                for (int k = i; k <= j; k++)
                {
                    prod *= nums[k];
                }

                res = max(prod, res);
            }
        }

        return res;
    }
};

class Better_Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        // Initialize result with the first element to handle single-element arrays
        int result = nums[0];

        // The outer loop picks the starting element of the subarray
        for (int i = 0; i < n; i++)
        {

            // 'p' stores the running product of the current subarray.
            // Reset to 1 for every new starting position 'i'.
            int p = 1;

            // The inner loop extends the subarray from index 'i' to the end of the array
            for (int j = i; j < n; j++)
            {

                // Multiply the current element to the running product
                p *= nums[j];

                // Track the maximum product found so far
                result = max(result, p);
            }
        }

        return result;
    }
};

/**
 * To optimize this from $O(n^2)$ down to $O(n)$ time complexity, we can use a variation of Kadane's Algorithm.
 * The trick with multiplication (unlike addition) is that a negative number can suddenly become the maximum possible product if it is multiplied by another negative number.
 * Therefore, as we traverse the array, we must keep track of both the maximum product and the minimum product up to the current position.
 */

class Optimal_Solution_1
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        // Initialize overall result, and track max/min products ending at the current position
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];

        // Traverse the array starting from the second element
        for (int i = 1; i < n; i++)
        {
            int curr = nums[i];

            // If the current element is negative, multiplying by it swaps the max and min.
            // (e.g., a big positive becomes a small negative, a small negative becomes a big positive)
            if (curr < 0)
            {
                swap(max_so_far, min_so_far);
            }

            // Decide whether to add the current element to the existing subarray product,
            // or start a completely new subarray from the current element.
            max_so_far = max(curr, max_so_far * curr);
            min_so_far = min(curr, min_so_far * curr);

            // Update the global maximum product found across all subarrays
            result = max(result, max_so_far);
        }

        return result;
    }
};

/**
 * Prefix-Suffix approach or a variation of the two-pointer observation for the Maximum Product Subarray problem.
 */

class Optimal_Solution_2
{
public:
    /* Function to find the product of
    elements in maximum product subarray */
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        int ans = INT_MIN; // to store the answer

        // Indices to store the prefix and suffix multiplication
        int prefix = 1, suffix = 1;

        // Iterate on the elements of the given array
        for (int i = 0; i < n; i++)
        {

            /* Resetting the prefix and suffix
            multiplication if they turn out to be zero */
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            // update the prefix and suffix multiplication
            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            // store the maximum as the answer
            ans = max(ans, max(prefix, suffix));
        }

        // return the result
        return ans;
    }
};