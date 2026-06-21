// 127. Word Ladder
// Hard
// Topics
// premium lock icon
// Companies
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

// Constraints:

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginword, string endword, vector<string> &wordList)
    {
        // Queue to store pairs of {current_word, current_transformation_length}
        // BFS is ideal here because it finds the shortest path in an unweighted graph
        queue<pair<string, int>> q;
        q.push({beginword, 1}); // Start with the beginword, which has a path length of 1

        // Transfer wordList to a hash set for O(1) lookups and easy tracking of unvisited words
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Prevent cycling back to the start word by removing it from the set immediately
        st.erase(beginword);

        // Begin BFS traversal
        while (!q.empty())
        {
            string word = q.front().first;
            int len = q.front().second;
            q.pop();

            // Base Case: If we reach the target word, return the current step count
            if (word == endword)
                return len;

            // Try changing each character of the current word one by one
            for (int i = 0; i < word.size(); i++)
            {
                char org = word[i]; // Store the original character to restore it later

                // Try replacing the current character with every letter from 'a' to 'z'
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;

                    // If the modified word exists in our unvisited word pool (set)
                    if (st.find(word) != st.end())
                    {
                        // Remove it from the set so we don't visit it again (acts as a 'visited' array)
                        st.erase(word);

                        // Push the valid transformed word into the queue with an incremented path length
                        q.push({word, len + 1});
                    }
                }

                // Revert back to the original character before moving to the next position
                word[i] = org;
            }
        }

        // If the queue becomes empty and the endword wasn't reached, no valid transformation exists
        return 0;
    }
};