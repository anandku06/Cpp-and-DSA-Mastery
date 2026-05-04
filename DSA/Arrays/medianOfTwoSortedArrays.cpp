// 4. Median of Two Sorted Arrays
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

// approach: Brute Force
// Intuition
// We can merge the two sorted arrays into a single sorted array and then find the median of the merged array. The median is the middle element of the sorted array if the number of elements is odd, or the average of the two middle elements if the number of elements is even.
// Time Complexity: O(m + n) for merging the two arrays and O(1) for finding the median, resulting in an overall time complexity of O(m + n).

// approach: Better Approach
// Intuition
// We can use a more efficient approach that does not require merging the two arrays. We can use two pointers to traverse both arrays simultaneously and find the median without actually merging them. We will keep track of the current elements from both arrays and the count of elements we have seen so far. When we reach the middle element(s), we can calculate the median based on whether the total number of elements is odd or even.
// Time Complexity: O(m + n) in the worst case when we have to traverse both arrays, but it can be more efficient if the median is found before traversing all elements.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        int totalSize = n + m; // total number of elements in the merged array

        int idx1 = (totalSize / 2) - 1; // index of the first middle element (if totalSize is even) or the middle element (if totalSize is odd)
        int elem1 = -1;

        int idx2 = totalSize / 2; // index of the second middle element (if totalSize is even) or the middle element (if totalSize is odd)
        int elem2 = -1;

        int i = 0, j = 0, k = 0; // pointers for nums1, nums2, and the merged array

        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j]) // if the current element in nums1 is smaller than the current element in nums2
            {
                if (k == idx1)        // if we have reached the first middle index
                    elem1 = nums1[i]; // store the element at idx1
                if (k == idx2)        // if we have reached the second middle index
                    elem2 = nums1[i]; // store the element at idx2
                i++;                  // move the pointer for nums1
            }
            else // if the current element in nums2 is smaller than or equal to the current element in nums1
            {
                if (k == idx1)        // if we have reached the first middle index
                    elem1 = nums2[j]; // store the element at idx1
                if (k == idx2)        // if we have reached the second middle index
                    elem2 = nums2[j]; // store the element at idx2
                j++;                  // move the pointer for nums2
            }

            k++; // move the pointer for the merged array
        }

        while (i < n)
        {
            if (k == idx1)
                elem1 = nums1[i];
            if (k == idx2)
                elem2 = nums1[i];

            i++;
            k++;
        }

        while (j < m)
        {
            if (k == idx1)
                elem1 = nums2[j];
            if (k == idx2)
                elem2 = nums2[j];

            j++;
            k++;
        }

        if (totalSize % 2 != 0) // if the total number of elements is odd, return the middle element
            return elem2;

        // if the total number of elements is even, return the average of the two middle elements
        return (elem1 + elem2) / 2.0;
    }
};

class Solution2
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m) // ensure that nums1 is the smaller array to optimize the binary search
            return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = n; // binary search on the smaller array

        // We are trying to find the correct partition of the two arrays such that the left half contains the smaller elements and the right half contains the larger elements. The median will be the maximum of the left half and the minimum of the right half.
        while (l <= r)
        {
            int mid1 = l + (r - l) / 2;        // partition index for nums1
            int mid2 = (n + m + 1) / 2 - mid1; // partition index for nums2

            int left1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1]; // max element on the left side of nums1
            int right1 = (mid1 == n) ? INT_MAX : nums1[mid1];    // min element on the right side of nums1

            int left2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1]; // max element on the left side of nums2
            int right2 = (mid2 == m) ? INT_MAX : nums2[mid2];    // min element on the right side of nums2

            if (left1 <= right2 && left2 <= right1)
            { // if we have found the correct partition
                if ((n + m) % 2 == 0)
                {                                                           // if the total number of elements is even
                    return (max(left1, left2) + min(right1, right2)) / 2.0; // return the average of the two middle elements
                }
                else
                {                             // if the total number of elements is odd
                    return max(left1, left2); // return the middle element
                }
            }
            else if (left1 > right2)
            { // if we are too far on the right side for nums1, move left
                r = mid1;
            }
            else
            { // if we are too far on the left side for nums1, move right
                l = mid1 + 1;
            }
        }

        return 0.0; // this line will never be reached, but we need to return something to satisfy the compiler
    }
};