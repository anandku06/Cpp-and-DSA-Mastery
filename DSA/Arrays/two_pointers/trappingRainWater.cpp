// 42. Trapping Rain Water
// Hard
// Topics
// premium lock icon
// Companies
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105

// approach : make two pointers, one at the start and one at the end, and check the left sum and right sum of each element, and the water trapped will be minimum of left sum and right sum - the element itself, and add it to the answer
// time complexity : O(n) and space complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (left < right)
        {
            // if the left height is less than the right height, then the water trapped will be determined by the left height, and if the left height is greater than or equal to the left max, then we update the left max, otherwise we add the water trapped to the answer, and we move the left pointer to the right, and if the right height is less than or equal to the right max, then we update the right max, otherwise we add the water trapped to the answer, and we move the right pointer to the left.
            if (height[left] < height[right]) // if the left height is less than the right height, then the water trapped will be determined by the left height, and if the left height is greater than or equal to the left max, then we update the left max, otherwise we add the water trapped to the answer, and we move the left pointer to the right, and if the right height is less than or equal to the right max, then we update the right max, otherwise we add the water trapped to the answer, and we move the right pointer to the left.
            {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];

                left++;
            }
            else // if the right height is less than or equal to the right max, then we update the right max, otherwise we add the water trapped to the answer, and we move the right pointer to the left.
            {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];

                right--;
            }
        }

        return ans;
    }
};

// why this works : if the left height is less than the right height, then the water trapped will be determined by the left height, and if the left height is greater than or equal to the left max, then we update the left max, otherwise we add the water trapped to the answer, and we move the left pointer to the right, and if the right height is less than or equal to the right max, then we update the right max, otherwise we add the water trapped to the answer, and we move the right pointer to the left.