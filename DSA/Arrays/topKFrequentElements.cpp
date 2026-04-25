// 347. Top K Frequent Elements
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2

// Output: [1,2]

// Example 2:

// Input: nums = [1], k = 1

// Output: [1]

// Example 3:

// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

// Output: [1,2]

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

// approach 1: O(n log n), using a hash map to count the frequency of each element and then sorting the elements based on their frequency and returning the top k elements.

// approach 2: O(n), using a hash map to count the frequency of each element and then using a bucket sort to sort the elements based on their frequency and returning the top k elements.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (nums.size() == k)
            return nums;

        unordered_map<int, int> hash;

        for (int i : nums)
        {
            hash[i]++;
        }

        // declare a priority Queue
        priority_queue<pair<int, int>> pq;

        for (auto &pair : hash)
        {
            pq.push({pair.second, pair.first}); // pushing the frequency and the element in the priority queue, so that the elements with higher frequency will be at the top of the queue
        }

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(pq.top().second); // getting the element from the top of the priority queue and adding it to the result vector
            pq.pop();
        }
        return result;
    }
};

// why we are pushing the frequency and the element in the priority queue, so that the elements with higher frequency will be at the top of the queue, and we can easily get the top k elements by popping the top k elements from the priority queue.