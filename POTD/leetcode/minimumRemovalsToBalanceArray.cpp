// 3634. Minimum Removals to Balance Array

// You are given an integer array nums and an integer k.

// An array is considered balanced if the value of its maximum element is at most k times the minimum element.

// You may remove any number of elements from nums​​​​​​​ without making it empty.

// Return the minimum number of elements to remove so that the remaining array is balanced.

// Note: An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.

// Example 1:

// Input: nums = [2,1,5], k = 2

// Output: 1

// Explanation:

// Remove nums[2] = 5 to get nums = [2, 1].
// Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.
// Example 2:

// Input: nums = [1,6,2,9], k = 3

// Output: 2

// Explanation:

// Remove nums[0] = 1 and nums[3] = 9 to get nums = [6, 2].
// Now max = 6, min = 2 and max <= min * k as 6 <= 2 * 3. Thus, the answer is 2.
// Example 3:

// Input: nums = [4,6], k = 2

// Output: 0

// Explanation:

// Since nums is already balanced as 6 <= 4 * 2, no elements need to be removed.

// using sliding window 2-pointer

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sorting zaroori hai kyunki sliding window tabhi kaam karegi jab humein pata ho ki window ka pehla element minimum hai aur aakhri element maximum.

        int i = 0, j = 0, L = 1;
        int maxEl, minEl;

        while (j < n)
        {
            maxEl = nums[j];
            minEl = nums[i];

            while (i < j && maxEl < (long long)k * minEl)
            {
                i++;
                minEl = nums[i];
            }

            L = max(L, j - i + 1);
            j++;
        }

        return n - L;
    }
};

// 1. Sorting Kyun Zaroori Hai?Agar array sorted nahi hai, toh humein pata hi nahi chalega ki kaunsa element sabse chota (min) hai aur kaunsa sabse bada (max). Sorting ke baad: Window ka pehla element (nums[i]) hamesha us range ka minimum hoga.Window ka aakhri element (nums[j]) hamesha us range ka maximum hoga.
// 2. Condition Ka MatlabCondition hai: $maxEl <= k * minEl. Iska simple matlab ye hai ki array ke kisi bhi subset mein sabse bada number, sabse chhote number ke $k$ times se zyada nahi hona chahiye.
// 3. Sliding Window Kaise Kaam Kar Rahi Hai?Aapka code ek "Expand and Shrink" strategy use kar raha hai: Expand (j++): Hum window ko bada karte hain ek naya number (nums[j]) add karke. Hum maante hain ki ye naya number ab hamara maxEl hai.Check & Shrink (i++): Jaise hi naya number add hota hai, hum check karte hain: "Kya ab ye window 'illegal' ho gayi?"Agar nums[j] > k * nums[i], toh iska matlab hai ki hamara minEl (jo ki nums[i] hai) bahut chhota hai. Hum i ko tab tak aage badhate hain jab tak condition phir se sahi na ho jaye.