// 88. Merge Sorted Array
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
// Example 3:

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

// Constraints:

// nums1.length == m + n
// nums2.length == n
// 0 <= m, n <= 200
// 1 <= m + n <= 200
// -109 <= nums1[i], nums2[j] <= 109

// Follow up: Can you come up with an algorithm that runs in O(m + n) time?

// approach
// We can solve this problem by using three pointers. We will have one pointer for nums1, one pointer for nums2, and one pointer for the end of the merged array. We will compare the elements at the pointers of nums1 and nums2 and place the larger element at the end of the merged array. We will then move the pointer of the array from which we took the element and also move the pointer for the end of the merged array. We will continue this process until we have merged all elements from both arrays.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Initialize 'i' to point to the last actual element in nums1
        int i = m - 1;

        // Initialize 'j' to point to the last element in nums2
        int j = n - 1;

        // Initialize 'k' to point to the very last index of the allocated space in nums1
        // (Since nums1 has a total capacity of m + n, the last index is m + n - 1)
        int k = m + n - 1;

        // The loop continues as long as there are elements left in nums2 to process.
        // We don't track 'i >= 0' here because if nums1 runs out first, we still need
        // to finish copying elements from nums2.
        while (j >= 0)
        {

            // Check if nums1 still has elements left (i >= 0)
            // AND if the current element in nums1 is strictly greater than the one in nums2.
            if (i >= 0 && nums1[i] > nums2[j])
            {

                // Place the larger element from nums1 into the current end position 'k'
                // Then, decrement both 'k' and 'i' to move backward
                nums1[k--] = nums1[i--];
            }
            // This block executes if:
            // 1. The element in nums2 is greater than or equal to the element in nums1, OR
            // 2. nums1 is completely exhausted (i < 0)
            else
            {

                // Place the element from nums2 into the current end position 'k'
                // Then, decrement both 'k' and 'j' to move backward
                nums1[k--] = nums2[j--];
            }
        }
        // Once j drops below 0, all elements from nums2 have been merged.
        // Any remaining elements in nums1 are already in their correct, sorted positions.
    }
};