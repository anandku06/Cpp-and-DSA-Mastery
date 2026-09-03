// 3876. Construct Uniform Parity Array II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array nums1 of n distinct integers.

// You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

// For each index i, you must choose exactly one of the following (in any order):

// nums2[i] = nums1[i]​​​​​​​
// nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
// Return true if it is possible to construct such an array, otherwise return false.

// Example 1:

// Input: nums1 = [1,4,7]

// Output: true

// Explanation:​​​​​​​​​​​​​​

// Set nums2[0] = nums1[0] = 1.
// Set nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3.
// Set nums2[2] = nums1[2] = 7.
// nums2 = [1, 3, 7], and all elements are odd. Thus, the answer is true.
// Example 2:

// Input: nums1 = [2,3]

// Output: false

// Explanation:

// It is not possible to construct nums2 such that all elements have the same parity. Thus, the answer is false.

// Example 3:

// Input: nums1 = [4,6]

// Output: true

// Explanation:

// Set nums2[0] = nums1[0] = 4.
// Set nums2[1] = nums1[1] = 6.
// nums2 = [4, 6], and all elements are even. Thus, the answer is true.

// Constraints:

// 1 <= n == nums1.length <= 105
// 1 <= nums1[i] <= 109
// nums1 consists of distinct integers.

// approach: The problem can be solved by checking the parity of the elements in the input array. If all elements are even or all elements are odd, we can construct the desired array. If there is a mix of even and odd elements, we need to check if we can create an array with uniform parity by using the allowed operations. Specifically, we can check if there exists at least one pair of elements such that their difference is odd, which would allow us to create an array with uniform parity.

// observation: If the smallest element in the array is odd, then we can only construct an array with odd elements. If the smallest element is even, then we cannot construct an array with uniform parity if there are any odd elements present. Therefore, we can check the parity of the smallest element and the presence of odd elements to determine if it is possible to construct an array with uniform parity.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        int n = nums1.size(); // get the size of the input array
        int evenCount = 0;    // initialize a counter for even numbers
        int oddCount = 0;     // initialize a counter for odd numbers

        for (int i = 0; i < n; i++)
        {
            if (nums1[i] % 2 == 0)
                evenCount++; // increment the even counter if the current element is even
            else
                oddCount++; // increment the odd counter if the current element is odd
        }

        // If all elements are even or all elements are odd, we can construct the desired array
        if (evenCount == n || oddCount == n)
            return true;

        // if there is a mix of even and odd elements, then we check if the smallest element is odd, then only odd elements can be constructed, and if the smallest element is even, then not possible to construct an array with uniform parity.

        int smallest = *min_element(nums1.begin(), nums1.end()); // find the smallest element in the array

        if (smallest % 2 == 1) // if the smallest element is odd
            return true;       // we can construct an array with all odd elements

        // if the smallest element is even
        return oddCount == 0; // we can only construct an array with all even elements if there are no odd elements present
    }
};