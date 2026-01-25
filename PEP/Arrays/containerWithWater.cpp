// 11. Container with Most Water

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int containerWithMostWater(vector<int>& heights){
            int n = heights.size();

            int i = 0, j = n - 1;
            int maxArea = 0;

            while (i < j)
            {
                int l = min(heights[i], heights[j]);
                int b = j - i;

                int area = l * b;

                maxArea = max(area, maxArea);

                if(heights[i] > heights[j]) j--;
                else i++;
            }

            return maxArea;
        }
};