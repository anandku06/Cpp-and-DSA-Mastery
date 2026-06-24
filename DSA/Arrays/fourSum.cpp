// 18. 4Sum
// Medium
// Topics
// premium lock icon
// Companies
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        // 1. Sort the array to use the two-pointer approach and easily skip duplicates
        sort(nums.begin(), nums.end());

        // 2. First pointer 'i' loops through the array for the 1st element
        for (int i = 0; i < n; i++)
        {
            // Skip duplicates for the 1st element to avoid duplicate quadruplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 3. Second pointer 'j' loops for the 2nd element, starting right after 'i'
            for (int j = i + 1; j < n; j++)
            {
                // Skip duplicates for the 2nd element
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // 4. Initialize two pointers for the remaining two elements
                int k = j + 1; // 'k' starts just after 'j' (left pointer)
                int l = n - 1; // 'l' starts at the end of the array (right pointer)

                // 5. Shrink the window from both sides
                while (k < l)
                {
                    // Use 'long long' to prevent integer overflow during addition
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        // Found a valid quadruplet, store it
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);

                        // Move both pointers inward to look for other combinations
                        k++, l--;

                        // Skip identical elements for 'k' to avoid duplicate results
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        // Skip identical elements for 'l' to avoid duplicate results
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        // Current sum is too small; move left pointer rightward to increase sum
                        k++;
                    }
                    else
                    {
                        // Current sum is too large; move right pointer leftward to decrease sum
                        l--;
                    }
                }
            }
        }

        // Return the final list of unique quadruplets
        return ans;
    }
};