// 31. Next Permutation

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]

// approach : treaversing from the end of the array, with the condition of (arr[i - 1] < arr[i])
//              if this condition is satisfied, mark the element on (i-1) index, and search for just bigger element for swapping and mark that as well.
//              after swapping, reverse the remain elements from the (i-1) till end.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        int mainIndex = -1; // the i index from the appraoch

        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                mainIndex = i - 1; // because that'll be my index for swapping
                break;
            }
        }

        if (mainIndex != -1)
        {
            int justBiggerIndex = mainIndex; // just bigger index for swapping
            for (int i = n - 1; i >= mainIndex + 1; i--)
            {
                if (nums[i] > nums[mainIndex])
                {
                    justBiggerIndex = i; // index stored here
                    break;
                }
            }

            swap(nums[mainIndex],
                 nums[justBiggerIndex]); // swapped the elements
                                         // permutation}
        }
        reverse(nums.begin() + mainIndex + 1,
                nums.end()); // and reversed the remain elements for next
    }
};