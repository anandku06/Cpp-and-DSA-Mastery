// 287. Find the Duplicate Number
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3

// Constraints:

// 1 <= n <= 105
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.

// Follow up:

// How can we prove that at least one duplicate number must exist in nums?
// Can you solve the problem in linear runtime complexity?

// Approach: Floyd's Tortoise and Hare (Cycle Detection)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Intuition: The idea is to use the concept of cycle detection in a linked list. We can treat the array as a linked list where the value at each index points to the next index. Since there is a duplicate number, there will be a cycle in the linked list. We can use Floyd's Tortoise and Hare algorithm to find the entry point of the cycle, which will be the duplicate number.

// How to identify Floyd's Tortoise and Hare algorithm in the code:
// 1. We have two pointers, one slow (tortoise) and one fast (hare).
// 2. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
// 3. If there is a cycle, the fast pointer will eventually meet the slow pointer.
// 4. Once they meet, we can reset one pointer to the start of the array and keep the other pointer at the meeting point. Then, we move both pointers one step at a time until they meet again. The point at which they meet will be the duplicate number.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int duplicateNumber(vector<int> &nums)
    {
        int slow = nums[0]; // initialize slow pointer to the first element of the array
        int fast = nums[0]; // initialize fast pointer to the first element of the array

        // find the meeting point of the two pointers
        do
        {
            slow = nums[slow];       // move slow pointer one step
            fast = nums[nums[fast]]; // move fast pointer two steps
        } while (slow != fast); // continue until they meet

        // find the entry point of the cycle
        slow = nums[0]; // reset slow pointer to the start of the array
        while (slow != fast)
        {                      // continue until they meet again
            slow = nums[slow]; // move slow pointer one step
            fast = nums[fast]; // move fast pointer one step
        }

        return slow; // return the duplicate number
    }
};

// here, we are using the values of the array as indices to move the pointers. bcz the values are in the range [1, n], we can use them as indices to move the pointers. This way, we can detect the cycle without modifying the array and using only constant extra space.