// 2452. Words Within Two Edits of Dictionary
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.

// In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.

// Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.

// Example 1:

// Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
// Output: ["word","note","wood"]
// Explanation:
// - Changing the 'r' in "word" to 'o' allows it to equal the dictionary word "wood".
// - Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it to "joke".
// - It would take more than 2 edits for "ants" to equal a dictionary word.
// - "wood" can remain unchanged (0 edits) and match the corresponding dictionary word.
// Thus, we return ["word","note","wood"].
// Example 2:

// Input: queries = ["yes"], dictionary = ["not"]
// Output: []
// Explanation:
// Applying any two edits to "yes" cannot make it equal to "not". Thus, we return an empty array.

// Constraints:

// 1 <= queries.length, dictionary.length <= 100
// n == queries[i].length == dictionary[j].length
// 1 <= n <= 100
// All queries[i] and dictionary[j] are composed of lowercase English letters.

// approach
// We can iterate through each word in queries and compare it with each word in dictionary. For each pair of words, we can count the number of edits required to make them equal. If the number of edits is less than or equal to 2, we can add the word from queries to the result list. Finally, we return the result list. The time complexity of this approach is O(m * n * k) where m is the length of queries, n is the length of dictionary, and k is the length of each word. The space complexity is O(m) for storing the result list.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries,
                                vector<string> &dictionary)
    {
        vector<string> res;

        for (string &q : queries)
        {
            for (string &s : dictionary)
            {
                int diff = 0;
                for (int i = 0; i < q.size(); i++)
                {
                    if (q[i] != s[i])
                        ++diff;
                    if (diff > 2)
                        break;
                }
                if (diff <= 2)
                {
                    res.push_back(q);
                    break;
                }
            }
        }

        return res;
    }
};