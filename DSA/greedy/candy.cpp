// 135. Candy
// Hard
// Topics
// premium lock icon
// Companies
// There are n children standing in a line.

// Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

// Example 1:

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
// Example 2:

// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.

// Constraints:

// 1 <= n == ratings.length <= 5 * 104
// 0 <= ratings[i] <= 5 * 104

// approach: The problem can be solved using a greedy algorithm. We can iterate through the ratings array from left to right and assign candies to each child based on their rating compared to their left neighbor. If the current child's rating is greater than the left neighbor's rating, we assign one more candy than the left neighbor. Otherwise, we assign one candy. After this pass, we iterate through the ratings array from right to left and update the candies assigned to each child based on their rating compared to their right neighbor. If the current child's rating is greater than the right neighbor's rating, we assign one more candy than the right neighbor. Finally, we sum up all the candies assigned to each child and return the total.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left to right pass
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left pass
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1); // max to ensure we don't decrease the candy count from the left to right pass
            }
        }

        // Sum up the total candies
        int totalCandies = accumulate(candies.begin(), candies.end(), 0);
        return totalCandies;
    }
};

// approach 2: Using 0(1) space complexity
// We can optimize the space complexity of the previous solution by using two variables to keep track of the current and previous candy counts instead of using an array. We can iterate through the ratings array from left to right and assign candies based on the rating compared to the left neighbor. Then, we can iterate from right to left and update the total candies based on the rating compared to the right neighbor. Finally, we return the total candies.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size(); // Get the number of children
        int candies = n;        // Each child gets at least one candy

        int i = 1;
        while (i < n)
        {
            if (ratings[i] == ratings[i - 1]) // If the current rating is equal to the previous rating
            {
                i++;
                continue; // Move to the next child
            }

            // Count the length of the increasing sequence
            int peak = 0;
            while (ratings[i] > ratings[i - 1]) // While the current rating is greater than the previous rating
            {
                peak++;
                candies += peak; // Add the peak to the total candies
                i++;

                if (i == n) // If we reach the end of the array
                    break;
            }

            // Count the length of the decreasing sequence
            int valley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) // While the current rating is less than the previous rating
            {
                valley++;
                candies += valley; // Add the valley to the total candies
                i++;
            }

            // Note that we added candies coming from left to Peak and comgin from right to Peak
            // But, we need to consider only max from both of them for the Peak.
            // So, remove the min candy from Peak.
            candies -= min(peak, valley);
        }

        return candies; // Return the total number of candies needed
    }
};