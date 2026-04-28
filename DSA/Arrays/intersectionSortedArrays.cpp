// 349. Intersection of Two Arrays
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

// approach
// We can solve this problem by using a set to store the unique elements of the first array and then iterating through the second array to check if any of its elements are present in the set. If they are, we can add them to a result set to ensure uniqueness. Finally, we can convert the result set to a vector and return it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s(nums1.begin(), nums1.end()); // Create a set from the first array
        unordered_set<int> result;                        // Set to store the unique intersection elements

        // Iterate through the second array and check for intersection
        for (int num : nums2)
        {
            if (s.find(num) != s.end())
            {                       // If the element is in the set
                result.insert(num); // Add it to the result set
            }
        }

        // Convert the result set to a vector
        return vector<int>(result.begin(), result.end());
    }

    vector<int> intersection2(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s(nums1.begin(), nums1.end()); // Create a set from the first array
        vector<int> result;                               // Vector to store the unique intersection elements

        // Iterate through the second array and check for intersection
        for (int num : nums2)
        {
            if (s.find(num) != s.end())
            {                          // If the element is in the set
                result.push_back(num); // Add it to the result vector
                s.erase(num);          // Remove it from the set to ensure uniqueness
            }
        }

        return result;
    }

    // If the input arrays are sorted, we can use a two-pointer approach to find the intersection in O(n + m) time.
    vector<int> intersectionSorted(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        int i = 0, j = 0;

        // Use two pointers to find the intersection of the two sorted arrays
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                // If the current element is the same in both arrays and it's not already in the result, add it to the result
                if (result.empty() || result.back() != nums1[i])
                {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++; // Move the pointer in the first array
            }
            else
            {
                j++; // Move the pointer in the second array
            }
        }

        return result;
    }
};