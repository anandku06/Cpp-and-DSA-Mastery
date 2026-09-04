// 455. Assign Cookies
// Easy
// Topics
// premium lock icon
// Companies
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

// Example 1:

// Input: g = [1,2,3], s = [1,1]
// Output: 1
// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
// And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
// You need to output 1.
// Example 2:

// Input: g = [1,2], s = [1,2,3]
// Output: 2
// Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
// You have 3 cookies and their sizes are big enough to gratify all of the children,
// You need to output 2.

// Constraints:

// 1 <= g.length <= 3 * 104
// 0 <= s.length <= 3 * 104
// 1 <= g[i], s[j] <= 231 - 1

// Note: This question is the same as 2410: Maximum Matching of Players With Trainers.

// approach: The problem can be solved using a greedy algorithm. We can sort both the greed factors of the children and the sizes of the cookies in non-decreasing order. Then, we can iterate through the sorted greed factors and try to assign the smallest available cookie that satisfies each child's greed factor. If a cookie is assigned to a child, we move on to the next child and the next cookie. If a cookie cannot satisfy a child's greed factor, we move on to the next cookie until we find one that does or run out of cookies. Finally, we return the count of content children.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int gn = g.size();
        int sn = s.size();

        sort(g.begin(), g.end()); // sort the greed factors of the children in non-decreasing order
        sort(s.begin(), s.end()); // sort the sizes of the cookies in non-decreasing

        int i = 0; // index for children
        int j = 0; // index for cookies

        while (i < gn && j < sn) // iterate through the sorted greed factors and sizes of cookies
        {
            if (s[j] >= g[i]) // if the size of the cookie is greater than or equal to the greed factor of the child
            {
                i++; // move on to the next child
            }
            j++; // move on to the next cookie
        }

        return i; // return the count of content children
    }
};