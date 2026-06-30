// 128. Longest Consecutive Sequence
// Medium
// Topics
// premium lock icon
// Companies
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// Example 3:

// Input: nums = [1,0,1,2]
// Output: 3

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109

// approach 1: using a hash set to store the elements of the array, and then for each element, checking the length of the consecutive sequence starting from that element. The time complexity of this approach is O(n) where n is the number of elements in the array.

// approach 2: sorting the array and then checking the length of the consecutive sequence. The time complexity of this approach is O(n log n) where n is the number of elements in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSequenceBySorting(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size(); // if the array has 0 or 1 element, then the longest consecutive sequence is the size of the array itself

        sort(nums.begin(), nums.end()); // sorting the array

        int longest = 1; // to store the length of the longest consecutive sequence
        int current = 1; // to store the length of the current consecutive sequence

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue; // if the current element is the same as the previous element, then we can skip it
            }
            else if (nums[i] == nums[i - 1] + 1)
            {
                current++;                       // if the current element is one more than the previous element, then we can increment the current consecutive sequence length
                longest = max(longest, current); // if the current element is not one more than the previous element, then we can update the longest consecutive sequence length and reset the current consecutive sequence length to 1
            }
            else
            {
                current = 1;
            }
        }

        return longest; // returning the longest consecutive sequence length
    }

    int longestSequenceByHashSet(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size(); // if the array has 0 or 1 element, then the longest consecutive sequence is the size of the array itself

        unordered_set<int> hashSet; // to store the elements of the array
        for (int num : nums)
        {
            hashSet.insert(num); // inserting the elements of the array into the hash set
        }

        int longest = 1; // to store the length of the longest consecutive sequence
        for (int i : hashSet)
        {
            if (hashSet.count(i - 1))
            {
                continue; // if the current element is one more than the previous element, then we can skip it
            }
            else if (hashSet.count(i + 1))
            {
                int current = 1;  // to store the length of the current consecutive sequence
                int next = i + 1; // to store the next element in the consecutive sequence

                while (hashSet.count(next))
                {
                    current++; // if the next element is in the hash set, then we can increment the current consecutive sequence length and update the next element
                    next++;
                }

                longest = max(longest, current); // if the next element is not in the hash set, then we can update the longest consecutive sequence length
            }
        }
        return longest; // returning the longest consecutive sequence length
    }
};