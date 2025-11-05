// Given an array nums, find the sum of elements of array using recursion.


// Examples:
// Input : nums = [1, 2, 3]

// Output : 6

// Explanation : The sum of elements of array is 1 + 2 + 3 => 6.

// Input : nums = [5, 8, 1]

// Output : 14

// Explanation : The sum of elements of array is 5 + 8 + 1 => 14.

// Input : nums = [12, 9, 17]

// Output:
// 38
// Constraints:
// 1 <= n <= 100
// 1 <= nums[i] <= 100

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySum(vector<int>& nums) {
        // Start from index 0
        return sum(nums, 0);
    }

private:
    int sum(vector<int>& nums, int left) {
        // Base case: out of bounds
        if (left >= nums.size()) {
            return 0;
        }
        // Add current element and recurse
        return nums[left] + sum(nums, left + 1);
    }
};

// Main method for testing
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};   
    int result = solution.arraySum(nums); 
    cout << result << endl;     
    return 0;
}
