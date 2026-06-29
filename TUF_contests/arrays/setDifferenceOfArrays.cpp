// Set difference of two arrays
// Medium

// Given two sorted arrays nums1 and nums2, return an array that contains the set difference of these two arrays. The elements in the set difference must be in ascending order.

// The set difference of two arrays is an array where all values are distinct and are present in either the first array or the second array, but not in both.

// Example 1

// Input: nums1 = [1, 5, 7, 9], nums2 = [1, 3, 4, 7]

// Output: [3, 4, 5, 9]

// Explanation:

// [3, 4, 5, 9] where,

// [3, 4] come from nums2 and [5, 9] comes from nums1.

// Example 2

// Input: nums1 = [1, 2, 6, 6], nums2 = [-2, 2, 3, 4, 6]

// Output: [-2, 1, 3, 4]

// Explanation:

// [-2, 1, 3, 4] where,

// [1] comes from nums1 and [-2, 3, 4] from nums2.

// Constraints

// 1 <= nums1.length, nums2.length <= 105
// -104 <= nums1[i] , nums2[i] <= 104
// Both nums1 and nums2 are sorted in non-decreasing order

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> setDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2)
        {
            // Skip duplicates in nums1
            if (i > 0 && nums1[i] == nums1[i - 1])
            {
                i++;
                continue;
            }
            // Skip duplicates in nums2
            if (j > 0 && nums2[j] == nums2[j - 1])
            {
                j++;
                continue;
            }

            if (nums1[i] < nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else if (nums2[j] < nums1[i])
            {
                result.push_back(nums2[j]);
                j++;
            }
            else
            {
                // Elements are equal, skip both to exclude them from the difference
                int matchVal = nums1[i];
                while (i < n1 && nums1[i] == matchVal)
                    i++;
                while (j < n2 && nums2[j] == matchVal)
                    j++;
            }
        }

        // Collect remaining unique elements from nums1
        while (i < n1)
        {
            if (i == 0 || nums1[i] != nums1[i - 1])
            {
                result.push_back(nums1[i]);
            }
            i++;
        }

        // Collect remaining unique elements from nums2
        while (j < n2)
        {
            if (j == 0 || nums2[j] != nums2[j - 1])
            {
                result.push_back(nums2[j]);
            }
            j++;
        }

        return result;
    }
};