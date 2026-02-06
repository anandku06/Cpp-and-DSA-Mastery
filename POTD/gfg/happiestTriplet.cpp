// You are given three arrays a[], b[], c[] of the same size . Find a triplet such that (maximum-minimum) in that triplet is the minimum of all the triplets. A triplet should be selected so that it should have one number from each of the three given arrays. This triplet is the happiest among all the possible triplets. Print the triplet in decreasing order.

// Note: If there are 2 or more smallest difference triplets, then the one with the smallest sum of its elements should be displayed.

// Examples:

// Input: a[] = [5, 2, 8] , b[] = [10, 7, 12] , c[] = [9, 14, 6]
// Output: [7, 6, 5]
// Explanation: The triplet [5, 7, 6]  has difference (maximum - minimum)= (7 - 5) = 2 which is minimum of all triplets.  
// Input: a[] = [15, 12, 18, 9] , b[] = [10, 17, 13, 8] , c[] = [14, 16, 11, 5]
// Output: [11, 10, 9]
// Explanation: Multiple triplets have the same minimum difference, and among them [11, 10, 9] has the smallest sum, so it is chosen.
// Constraints:
// 1 ≤ a.size(), b.size() ,c.size() ≤ 105
// 1 ≤ a[i], b[i], c[i] ≤ 105

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> happiestTriplet(vector<int>& a, vector<int>& b, vector<int>& c) {
            vector<int> solution;

            int i = 0, j = 0, k = 0;
            int min_i = -1, min_j = -1, min_k = -1;

            int currAns = INT_MAX;

            while (i < a.size() && j < b.size() && k < c.size())
            {
                int newCurrAns = max(a[i], max(b[j], c[k])) - min(a[i], min(b[j], c[k]));
                if(newCurrAns < currAns) {
                    currAns = newCurrAns;
                    min_i = i;
                    min_j = j;
                    min_k = k;
                }

                if(a[i] <= b[j] && a[i] <= c[k]) i++;
                else if(b[j] <= a[i] && a[i] <= c[k]) j++;
                else k++;
            }

            solution = {a[min_i], b[min_j], c[min_k]};
            sort(solution.rbegin(), solution.rend());
            
            return solution;
        }
};