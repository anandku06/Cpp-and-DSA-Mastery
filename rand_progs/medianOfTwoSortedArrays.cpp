// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Example 1:

// Input: nums1 = [1,3], nums2 = [2] Output: 2.00000 Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4] Output: 2.50000 Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double median(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        int total = n + m;
        int mid = total / 2;
        bool isEven = (total % 2 == 0);

        int i = 0, j = 0, count = 0;
        double median1 = 0, median2 = 0;

        while (count <= mid)
        {
            int val;
            if (i < n && (j >= m || nums1[i] < nums2[j]))
            {
                val = nums1[i++];
            }
            else
            {
                val = nums2[j++];
            }

            if (count == mid - 1)
            {
                median1 = val;
            }
            if (count == mid)
            {
                median2 = val;
            }
            count++;
        }

        return isEven ? (median1 + median2) / 2.0 : median2;
    }
};