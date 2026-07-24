// 239. Sliding Window Maximum
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length

// Approach 1: Using a Deque
// Intuition
// We can use a deque to store the indices of the elements in the current window. The deque will always be in decreasing order of the values of the elements at those indices. This way, the front of the deque will always be the index of the maximum element in the current window. As we move the window, we will remove the indices that are out of the current window and also remove the indices of the elements that are smaller than the current element, as they will never be the maximum in any future window.

// Approach 2: Using a Max Heap
// Intuition
// We can use a max heap to store the elements in the current window. The top of the max heap will always be the maximum element in the current window. As we move the window, we will remove the elements that are out of the current window and also remove the elements that are smaller than the current element, as they will never be the maximum in any future window. However, this approach is less efficient than using a deque, as it takes O(log k) time to insert and remove elements from the max heap, while it takes O(1) time to insert and remove elements from the deque.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        deque<int> dq; // will store the indices of the elements in the current window

        for (int i = 0; i < nums.size(); i++)
        {
            // remove the indices that are out of the current window
            while (!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }

            // remove the indices of the elements that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            // add the current index to the deque
            dq.push_back(i);

            // if we have formed a valid window, add the maximum element to the result
            if (i >= k - 1)
            {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

/**
 * When new element comes, we make space for it by removing the smaller elements from the back of the deque. 
 * Now, when nums[i] comes, there is no need to keep small elements in that window, pop them
 * Now push i in deque -> for nums[i]
 * if(i >= k - 1) -> we have formed a valid window, so we can add the maximum element to the result
 */