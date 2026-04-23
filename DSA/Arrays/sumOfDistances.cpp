// 2615. Sum of Distances
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

// Return the array arr.

// Example 1:

// Input: nums = [1,3,1,1,2]
// Output: [5,0,3,4,0]
// Explanation:
// When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5.
// When i = 1, arr[1] = 0 because there is no other index with value 3.
// When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3.
// When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4.
// When i = 4, arr[4] = 0 because there is no other index with value 2.

// Example 2:

// Input: nums = [0,5,3]
// Output: [0,0,0]
// Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109

// thought process
// 1. We can use a hash map to store the indices of each element in the array.
// 2. For each element in the array, we can calculate the sum of distances to all other indices with the same value using the hash map.
// 3. We can use the formula for the sum of distances to calculate the sum in O(1) time for each element, after we have the indices stored in the hash map.

// formula : freq * i - sum of indices before i + sum of indices after i - freq * i

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;

    vector<ll> distanceSum(vector<int> &nums)
    {
        int n = nums.size();

        // result vector, of size n and values 0
        vector<ll> res(n, 0);

        // hash maps to store the sum of indices and count of indices for each value in nums
        unordered_map<int, ll> indexSum;
        unordered_map<int, ll> indexCount;

        // loop for left to right
        for (int i = 0; i < n; i++)
        {
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];

            // calculate the sum of distances for the current index using the formula
            res[i] += freq * i - sum;

            // update the hash maps with the current index
            indexSum[nums[i]] += i;
            indexCount[nums[i]]++;
        }

        // cleared the hash maps to reuse them for the right to left loop
        indexCount.clear();
        indexSum.clear();

        // loop for right to left
        for (int i = n - 1; i >= 0; i--)
        {
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];

            // calculate the sum of distances for the current index using the formula
            res[i] += sum - freq * i;

            // update the hash maps with the current index
            indexSum[nums[i]] += i;
            indexCount[nums[i]]++;
        }

        return res;
    }
};