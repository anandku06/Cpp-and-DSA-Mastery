// 3091. Apply Operations to Make Sum of Array Greater Than or Equal to k
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a positive integer k. Initially, you have an array nums = [1].

// You can perform any of the following operations on the array any number of times (possibly zero):

// Choose any element in the array and increase its value by 1.
// Duplicate any element in the array and add it to the end of the array.
// Return the minimum number of operations required to make the sum of elements of the final array greater than or equal to k.

// Example 1:

// Input: k = 11

// Output: 5

// Explanation:

// We can do the following operations on the array nums = [1]:

// Increase the element by 1 three times. The resulting array is nums = [4].
// Duplicate the element two times. The resulting array is nums = [4,4,4].
// The sum of the final array is 4 + 4 + 4 = 12 which is greater than or equal to k = 11.
// The total number of operations performed is 3 + 2 = 5.

// Example 2:

// Input: k = 1

// Output: 0

// Explanation:

// The sum of the original array is already greater than or equal to 1, so no operations are needed.

// Constraints:

// 1 <= k <= 105

// thought process
// 1. We can either increase an element by 1 or duplicate an element.
// 2. To minimize the number of operations, we should try to increase the largest element in the array first, as it will contribute more to the sum.
// 3. We can keep track of the sum of the array and the largest element, and perform the operations until the sum is greater than or equal to k.

// approach: Greedy
// 1. Initialize the sum of the array and the largest element.
// 2. While the sum is less than k, perform the following operations:
//    a. If the largest element is less than k, increase it by 1 and update the sum.
//    b. If the largest element is greater than or equal to k, duplicate it and update the sum.
// 3. Keep track of the number of operations performed and return it at the end.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(int k)
    {
        // initialise the minimum number of operations
        int minOps = k - 1; // worst case: we can increase the element by 1 until we reach k

        // i must be a number in the array, and it can be at most k, because if it is greater than k, we can just duplicate it to reach k
        // check for all numbers from 1 to sqrt(k) + 1, because if we duplicate a number greater than sqrt(k), it will be greater than k
        for (int i = 1; i < sqrt(k) + 1; i++)
        {
            int incOps = i - 1; // number of operations to increase the element to i
            // take the ceiling of k/i to get the number of times we need to duplicate the element to reach k
            int dupOps = (k + i - 1) / i; // number of operations to duplicate the element to reach k

            minOps = min(minOps, incOps + dupOps); // update the minimum number of operations
        }

        return minOps; // return the minimum number of operations
    }
};
