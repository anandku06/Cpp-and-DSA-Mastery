// 75. Sort Colors

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

// approach 1 -> direct sort using STL function -> O(nlogn)
// approach 2 -> count the number of occurences of each color and then just update the actual array with it and sorted
// approach 3 -> Assign 3 vars to the colors, as we know, there are only 3 colors and according to that swap the colors to thier respective vars with traversing it

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0; // for 0
        int m = 0; // for 1
        int j = nums.size() - 1; // for 2 , as 2 should be in last to make it sorted

        while (m <= j) // when m crosses j, the loop is traversed
        {
            if(nums[m] == 1) m++;

            // if the current element is 2, we will swap it with the element at index j and decrement j, because 2 should be in last to make it sorted
            else if(nums[m] == 2) {
                swap(nums[m], nums[j]);
                j--;
            }
            else {
                swap(nums[m], nums[i]);
                i++;
                m++;
            }
        }
        
    }
};