// 212. Word Search II
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

// Example 1:

// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:

// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.

// Approach: Trie + Backtracking
// We can use a trie to store the list of words and then perform a backtracking search on the board to find all the words in the trie. The backtracking search will explore all possible paths on the board and check if any of them match a word in the trie.
// Time Complexity: O(M * N * 4^L) where M and N are the dimensions of the board and L is the maximum length of words in the list.
// Space Complexity: O(W * L) where W is the number of words and L is the maximum length of words in the list.

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    bool isEndOfWord;
    string word; // To store the complete word at the end of the trie node
    unordered_map<char, TrieNode *> children;

    TrieNode() : isEndOfWord(false) {}
};

class Solution
{
public:
    vector<string> ans; // To store the found words
    int m, n;           // Dimensions of the board

    void insert(TrieNode *root, const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEndOfWord = true; // Mark the end of the word
        node->word = word;        // Store the complete word at the end of the trie node
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        m = board.size();    // Number of rows
        n = board[0].size(); // Number of columns

        TrieNode *root = new TrieNode(); // Create the root of the trie

        // Insert all words into the trie
        for (const string &word : words)
        {
            insert(root, word);
        }

        function<void(vector<vector<char>> &, int, int, TrieNode *)> backtrack = [&](vector<vector<char>> &board, int i, int j, TrieNode *node)
        {
            if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#' || !node->children.count(board[i][j]))
                return; // If we are out of bounds, the cell is already visited, or the current character is not in the trie, return

            TrieNode *curr = node->children[board[i][j]]; // Move to the child node corresponding to the current character

            if (curr->isEndOfWord)
            {
                ans.push_back(curr->word); // If we have found a complete word, add it to the answer list
                curr->isEndOfWord = false; // Mark the word as found to avoid duplicates
            }

            char temp = board[i][j]; // Store the current cell value
            board[i][j] = '#';       // Mark the current cell as visited

            // Explore all four possible directions (up, down, left, right)
            backtrack(board, i + 1, j, curr);
            backtrack(board, i - 1, j, curr);
            backtrack(board, i, j + 1, curr);
            backtrack(board, i, j - 1, curr);

            board[i][j] = temp; // Backtrack by restoring the original value of the cell
        };

        // traverse in the grid and search for the words in the trie
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char c = board[i][j];

                // If the current character is present in the trie, we start backtracking from that cell
                if (root->children.count(c))
                {
                    backtrack(board, i, j, root); // Start backtracking from the current cell
                }
            }
        }

        return ans; // Return the list of found words
    }
};