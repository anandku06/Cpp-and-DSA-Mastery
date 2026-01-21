// Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.


// Example 1

// Input : nums = [1, 2, 3, 4, 5]

// Output : true

// Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.

// Example 2

// Input : nums = [1, 2, 1, 4, 5]

// Output : false

// Explanation : For i == 2 it does not hold nums[i] <= nums[i+1], hence it is not sorted and we return false.

// Example 3

// Input : nums = [1,9,6,8,5,4,0]

// Output:

// false


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSorted(vector<int>& nums) {
        // An array with 0 or 1 element is always considered sorted
        if (nums.size() <= 1) {
            return true;
        }
        // Check if the array is sorted starting from index 0 to 1
        return sort(nums, 0, 1);
    }

private:
    bool sort(vector<int>& nums, int left, int right) {
        // If we reach the end of the array
        // it means the array is sorted
        if (right >= nums.size()) {
            return true;
        }
        // If we find a pair where the left element is greater than the right 
        // the array is not sorted
        if (nums[left] > nums[right]) {
            return false;
        }
        // Move to the next pair of elements
        return sort(nums, left + 1, right + 1);
    }
};

// Main method for testing the isSorted function
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5}; 
    bool result = solution.isSorted(nums); 
    cout << (result ? "Array is sorted" : "Array is not sorted") << endl; 
    return 0;
}