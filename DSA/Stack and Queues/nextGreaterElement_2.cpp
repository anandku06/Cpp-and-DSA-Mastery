// 503. Next Greater Element II
// Medium
// Topics
// premium lock icon
// Companies
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2;
// The number 2 can't find next greater number.
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

// Constraints:

// 1 <= nums.length <= 104
// -109 <= nums[i] <= 109

// approach: Using a Stack
// Intuition
// We can use a stack to keep track of the elements in nums. We will iterate through nums twice (to account for the circular nature of the array) and for each element, we will pop the elements from the stack until we find an element that is greater than the current element. The popped elements will have the current element as their next greater element. We will also store the next greater element for each popped element in a hash map. Finally, we will iterate through nums and for each element, we will check if it has a next greater element in the hash map. If it does, we will add it to the answer; otherwise, we will add -1 to the answer.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElementII(vector<int> &nums)
    {
        int n = nums.size();       // size of the array
        vector<int> result(n, -1); // initialize the result array with -1

        stack<int> st; // stack to keep track of the elements

        for (int i = 2 * n - 1; i >= 0; i--) // iterate through the array twice
        {
            int idx = i % n; // get the index of the current element

            while (!st.empty() && st.top() <= nums[idx]) // pop elements from the stack until we find a greater element
                st.pop();

            if (!st.empty()) // if the stack is not empty, the top element is the next greater element
                result[idx] = st.top();

            st.push(nums[idx]); // push the current element onto the stack
        }

        return result;
    }
};