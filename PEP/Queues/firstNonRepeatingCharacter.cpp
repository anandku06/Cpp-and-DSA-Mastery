// Stream First Non-repeating
// Difficulty: MediumAccuracy: 31.65%Submissions: 242K+Points: 4Average Time: 15m
// Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n), find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.

// Examples:

// Input: s = "aabc"
// Output: a#bb
// Explanation:
// At i=0 ("a"): First non-repeating character is 'a'.
// At i=1 ("aa"): No non-repeating character, so '#'.
// At i=2 ("aab"): First non-repeating character is 'b'.
// At i=3 ("aabc"): Non-repeating characters are 'b' and 'c'; 'b' appeared first, so 'b'.
// Input: s = "bb"
// Output: "b#"
// Explanation:
// At i=0 ("b"): First non-repeating character is 'b'.
// At i=1 ("bb"): No non-repeating character, so '#'.
// Constraints:
// 1 ≤ s.size() ≤ 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string &s)
    {
        vector<int> freq(26, 0); // Frequency array for 'a' through 'z'
        queue<char> q;
        string result = "";

        for (char ch : s)
        {
            // 1. Update frequency and push to queue
            freq[ch - 'a']++;
            q.push(ch);

            // 2. Pop repeating characters from the front
            while (!q.empty() && freq[q.front() - 'a'] > 1)
            {
                q.pop();
            }

            // 3. Determine the answer for the current prefix
            if (q.empty())
            {
                result += '#';
            }
            else
            {
                result += q.front();
            }
        }

        return result;
    }
};