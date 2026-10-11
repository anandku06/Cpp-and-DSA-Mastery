// 2333. Minimum Sum of Squared Difference
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

// The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.

// You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

// Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.

// Note: You are allowed to modify the array elements to become negative integers.

// Example 1:

// Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
// Output: 579
// Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0.
// The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.
// Example 2:

// Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
// Output: 43
// Explanation: One way to obtain the minimum sum of square difference is:
// - Increase nums1[0] once.
// - Increase nums2[2] once.
// The minimum of the sum of square difference will be:
// (2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
// Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.

// Constraints:

// n == nums1.length == nums2.length
// 1 <= n <= 105
// 0 <= nums1[i], nums2[i] <= 105
// 0 <= k1, k2 <= 109

// approach: Greedy, Priority Queue
// The idea is to use a max heap to keep track of the largest differences between the two arrays. We will repeatedly reduce the largest difference by 1 (or increase it by 1 if it's negative) until we have used up all of our allowed modifications (k1 + k2). After that, we will calculate the sum of squared differences.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        long long k = (long long)k1 + (long long)k2; // total number of modifications allowed
        priority_queue<long long> pq;                // max heap to store the absolute differences

        for (int i = 0; i < nums1.size(); i++)
        {
            pq.push(abs((long long)nums1[i] - (long long)nums2[i])); // push the absolute differences into the max heap
        }

        while (k > 0 && !pq.empty())
        {
            long long diff = pq.top(); // get the largest difference
            pq.pop();

            if (diff == 0)
                break; // if the largest difference is 0, we can't reduce it further

            diff--;        // reduce the largest difference by 1
            pq.push(diff); // push the reduced difference back into the max heap
            k--;           // decrement the number of modifications left
        }

        long long result = 0;
        while (!pq.empty())
        {
            long long diff = pq.top();
            pq.pop();
            result += diff * diff; // calculate the sum of squared differences
        }

        return result;
    }
};

// not using priority queue, using counting sort approach
class Solution
{
public:
    int minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        long long k = (long long)k1 + (long long)k2; // total number of modifications allowed
        vector<long long> count(100001, 0);          // count array to store the frequency of differences

        for (int i = 0; i < nums1.size(); i++)
        {
            long long diff = abs((long long)nums1[i] - (long long)nums2[i]);
            count[diff]++; // count the frequency of each difference
        }

        for (int i = 100000; i > 0 && k > 0; i--)
        {
            if (count[i] > 0)
            {
                long long reduce = min((long long)count[i], k); // determine how many differences we can reduce
                count[i] -= reduce;                             // reduce the count of the current difference
                count[i - 1] += reduce;                         // increase the count of the next lower difference
                k -= reduce;                                    // decrement the number of modifications left
            }
        }

        long long result = 0;
        for (int i = 0; i <= 100000; i++)
        {
            result += count[i] * i * i; // calculate the sum of squared differences
        }

        return result;
    }
}