// Maximum sum
// Hard

// Jax is trying to solve a problem but he has to go out to play with friends. So he ask you to solve the problem and he went to play with his friends.

// You are given an array and you have to maximize the sum of the array by using below two operations each once.

// 1) You can choose any prefix of the array (possibly empty) and multiply with -1.

// 2) You can choose any suffix of the array (possibly empty) and multiply with -1.

// The chosen prefix and suffix may intersect. You have to find the maximum sum of the array by performing the above operations.

// Example 1

// Input : nums = [-1, 2 , -3]

// Output : 6

// Explanation :

// In first operation we will choose the prefix array as [-1] and multiply it with -1.

// In second operation we will choose the suffix array as [-3] and multiply it with -1.

// The new array after the operations performed will be [1, 2, 3].

// The maximum sum would be => 1 + 2 + 3 => 6.

// Example 2

// Input : nums = [-1, 10, -5, 10, -2]

// Output : 18

// Explanation :

// The prefix chosen is [-1].

// The suffix chosen is [-2].

// The new array will be -> [1, 10, -5, 10, 2].

// Sum would be => 1 + 10 + (-5) + 10 + 2 => 18.

// Constraints

// 1 <= n <= 105
// 10-4 <= nums[i] <= 10-4

// Intuition : When we flip one prefix and one suffix, the middle segment (where both flips overlap) is effectively left unchanged. Hence, the array can be thought of as: [flipped prefix] + [kept middle] + [flipped suffix] where everything outside the middle gets its sign reversed. If the sum of the middle subarray is M and the total sum of the array is T, then the flipped parts contribute −(T − M) and the middle contributes +M. Thus, final total = 2*M − T. To maximize this, we need to choose the subarray with the maximum possible sum (Kadane’s algorithm). Since we can also flip the entire array (empty middle), we allow M = 0 as a valid case.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;

    int maximumSum(vector<int> &nums)
    {
        ll total = 0;
        for (int i : nums)
            total += i;

        ll best = LLONG_MIN; // To store the maximum sum of the array after performing the operations.
        ll curr = 0;         // To store the current sum of the array after performing the operations.

        for (int i : nums)
        {
            curr = (curr > 0 ? curr + i : i);
            best = max(best, curr);
        }

        ll keep = max(0LL, best);  // Allow empty middle segment
        ll ans = 2 * keep - total; // The maximum sum would be => 2 * keep - total.

        return (int)ans;
    }
};