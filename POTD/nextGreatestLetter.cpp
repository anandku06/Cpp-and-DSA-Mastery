// 744. Find Smallest Letter Greater Than Target

// You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

// Example 1:

// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
// Example 2:

// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
// Example 3:

// Input: letters = ["x","x","y","y"], target = "z"
// Output: "x"
// Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].

// approach: Using Binary Search, if the current letter is greater than the target, storing it(bcz can be a poss ans), and then changing the right to mid - 1
// if not then left to mid + 1;

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        char nextGreatestChar(vector<char>& letters, char target) {
            int left = 0;
            int right = letters.size() - 1;

            char ans = letters[0];

            while (left <= right)
            {
                int mid = (left + right) / 2;

                if(letters[mid] > target) {
                    right = mid - 1;
                    ans = letters[mid];
                } else left = mid + 1;
            }
            
            return ans;
        }
};