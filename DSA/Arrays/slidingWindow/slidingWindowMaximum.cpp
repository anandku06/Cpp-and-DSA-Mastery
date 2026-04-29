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

// Approach 3: Using a Balanced Binary Search Tree
// Intuition
// We can use a balanced binary search tree (like a multiset in C++) to store the elements in the current window. The maximum element in the current window will always be the last element in the balanced binary search tree. As we move the window, we will remove the elements that are out of the current window and also remove the elements that are smaller than the current element, as they will never be the maximum in any future window. However, this approach is less efficient than using a deque, as it takes O(log k) time to insert and remove elements from the balanced binary search tree, while it takes O(1) time to insert and remove elements from the deque.

// Approach 4: Using a Segment Tree
// Intuition
// We can use a segment tree to store the maximum element in each segment of the array. As we move the window, we can query the segment tree to get the maximum element in the current window. However, this approach is less efficient than using a deque, as it takes O(log n) time to query the segment tree, while it takes O(1) time to get the maximum element from the front of the deque.

// Approach 5: Using a Sparse Table
// Intuition
// We can use a sparse table to store the maximum element in each segment of the array. As we move the window, we can query the sparse table to get the maximum element in the current window. However, this approach is less efficient than using a deque, as it takes O(1) time to query the sparse table, but it takes O(n log n) time to build the sparse table, while it takes O(1) time to get the maximum element from the front of the deque and O(n) time to build the deque.

// Approach 6: Using a Monotonic Queue
// Intuition
// We can use a monotonic queue to store the indices of the elements in the current window. The monotonic queue will always be in decreasing order of the values of the elements at those indices. This way, the front of the monotonic queue will always be the index of the maximum element in the current window. As we move the window, we will remove the indices that are out of the current window and also remove the indices of the elements that are smaller than the current element, as they will never be the maximum in any future window. This approach is similar to using a deque, but it is more efficient as it takes O(1) time to insert and remove elements from the monotonic queue, while it takes O(1) time to insert and remove elements from the deque, but it takes O(n) time to build the deque, while it takes O(n) time to build the monotonic queue.

// Approach 7: Using a Balanced Binary Search Tree with Lazy Deletion
// Intuition
// We can use a balanced binary search tree (like a multiset in C++) to store the elements in the current window. The maximum element in the current window will always be the last element in the balanced binary search tree. As we move the window, we will remove the elements that are out of the current window and also remove the elements that are smaller than the current element, as they will never be the maximum in any future window. However, instead of removing the elements from the balanced binary search tree immediately, we can mark them for lazy deletion and only remove them when they are at the top of the balanced binary search tree. This way, we can avoid unnecessary removals from the balanced binary search tree and improve the efficiency of this approach. However, this approach is still less efficient than using a deque, as it takes O(log k) time to insert and remove elements from the balanced binary search tree, while it takes O(1) time to insert and remove elements from the deque.

// Approach 8: Using a Deque with Lazy Deletion
// Intuition
// We can use a deque to store the indices of the elements in the current window. The deque will always be in decreasing order of the values of the elements at those indices. This way, the front of the deque will always be the index of the maximum element in the current window. As we move the window, we will remove the indices that are out of the current window and also remove the indices of the elements that are smaller than the current element, as they will never be the maximum in any future window. However, instead of removing the indices from the deque immediately, we can mark them for lazy deletion and only remove them when they are at the front of the deque. This way, we can avoid unnecessary removals from the deque and improve the efficiency of this approach. However, this approach is still less efficient than using a regular deque, as it takes O(1) time to insert and remove elements from a regular deque, while it takes O(1) time to insert and remove elements from a deque with lazy deletion, but it takes O(n) time to build a regular deque, while it takes O(n) time to build a deque with lazy deletion.

// Approach 9: Using a Deque with a Hash Map for Lazy Deletion
// Intuition
// We can use a deque to store the indices of the elements in the current window. The deque will always be in decreasing order of the values of the elements at those indices. This way, the front of the deque will always be the index of the maximum element in the current window. As we move the window, we will remove the indices that are out of the current window and also remove the indices of the elements that are smaller than the current element, as they will never be the maximum in any future window. However, instead of removing the indices from the deque immediately, we can use a hash map to keep track of which indices are marked for lazy deletion and only remove them when they are at the front of the deque. This way, we can avoid unnecessary removals from the deque and improve the efficiency of this approach. However, this approach is still less efficient than using a regular deque, as it takes O(1) time to insert and remove elements from a regular deque, while it takes O(1) time to insert and remove elements from a deque with a hash map for lazy deletion, but it takes O(n) time to build a regular deque, while it takes O(n) time to build a deque with a hash map for lazy deletion.

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