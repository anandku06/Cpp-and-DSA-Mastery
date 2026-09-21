// 2104. Sum of Subarray Ranges
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
// Example 2:

// Input: nums = [1,3,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [3], range = 3 - 3 = 0
// [3], range = 3 - 3 = 0
// [1,3], range = 3 - 1 = 2
// [3,3], range = 3 - 3 = 0
// [1,3,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
// Example 3:

// Input: nums = [4,-2,-3,4,1]
// Output: 59
// Explanation: The sum of all subarray ranges of nums is 59.

// Constraints:

// 1 <= nums.length <= 1000
// -109 <= nums[i] <= 109

// Follow-up: Could you find a solution with O(n) time complexity?

// approach: Using a Stack
// Intuition
// We can find the previous less element and the next less element for each element in the array. The previous less element is the first element to the left of the current element that is less than the current element. The next less element is the first element to the right of the current element that is less than the current element.
// The number of subarrays in which the current element is the minimum is equal to the product of the distance to the previous less element and the distance to the next less element. We can then multiply this count by the value of the current element to get its contribution to the sum of subarray minimums. Finally, we can sum up all contributions and return the result modulo 10^9 + 7.