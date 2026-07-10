// Coin Piles
// Difficulty: MediumAccuracy: 20.51%Submissions: 47K+Points: 4Average Time: 20m
// You are given an array arr[] of integers, where each element represents the number of coins in a pile. You are also given an integer k.
// Your task is to remove the minimum number of coins such that the absolute difference between the number of coins in any two updated piles is at most k.

// Note: You can also remove a pile by removing all the coins of that pile.

// Examples:

// Input: arr[] = [2, 2, 2, 2], k = 0
// Output: 0
// Explanation: For any two piles the difference in the number of coins is <= 0. So no need to remove any coin.
// Input: arr[] = [1, 5, 1, 2, 5, 1], k = 3
// Output: 2
// Explanation: If we remove one coin each from both the piles containing 5 coins, then for any two piles the absolute difference in the number of coins is <= 3.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104
// 0 ≤ k ≤ 104

// approach: We can sort the array and then use a two-pointer technique to find the minimum number of coins to remove. We will iterate through the sorted array and for each pile, we will find the maximum pile that can be paired with it such that the difference is at most k. The number of coins to remove will be the total number of coins minus the sum of the coins in the valid piles.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCoins(vector<int> &arr, int k)
    {
        int n = arr.size();

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: Compute Prefix Sums
        vector<long long> pref(n, 0);
        pref[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + arr[i];
        }

        long long min_removals = LLONG_MAX;
        long long coins_removed_before = 0; // Tracks coins removed from completely eliminated piles

        // Step 3: Iterate through each pile as the potential minimum
        for (int i = 0; i < n; i++)
        {
            // Optimization: Skip duplicates to avoid redundant checks
            if (i > 0 && arr[i] == arr[i - 1])
            {
                coins_removed_before += arr[i - 1];
                continue;
            }

            int target_max = arr[i] + k;

            // Find the first element > target_max using binary search
            auto it = upper_bound(arr.begin(), arr.end(), target_max);
            int idx = distance(arr.begin(), it);

            long long current_removals = coins_removed_before;

            // If there are elements greater than target_max, calculate reductions
            if (idx < n)
            {
                long long total_upper_sum = pref[n - 1] - (idx > 0 ? pref[idx - 1] : 0);
                long long elements_count = n - idx;

                current_removals += total_upper_sum - (elements_count * target_max);
            }

            min_removals = min(min_removals, current_removals);

            // Accumulate for the next iteration's prefix cost
            coins_removed_before += arr[i];
        }

        return min_removals;
    }
};