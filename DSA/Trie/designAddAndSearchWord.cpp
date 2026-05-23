// 211. Design Add and Search Words Data Structure
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True

// Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 2 dots in word for search queries.
// At most 104 calls will be made to addWord and search.

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode *> children;

    TrieNode() : isEndOfWord(false) {}
};

class WordDictionary
{
public:
    TrieNode *root;

    WordDictionary()
    {
        root = new TrieNode(); // Initialize the root of the trie
    }

    void addWord(string word)
    {
        TrieNode *currentNode = root; // Start from the root node
        for (char c : word)
        {
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                currentNode->children[c] = new TrieNode(); // Create a new node if it doesn't exist
            }
            currentNode = currentNode->children[c]; // Move to the child node
        }
        currentNode->isEndOfWord = true; // Mark the end of the word
    }

    bool search(string word)
    {
        return searchHelper(word, 0, root); // Start the search from the root node and index 0x
    }

private:
    bool searchHelper(const string &word, int index, TrieNode *currentNode)
    {
        if (index == word.size())
        {
            return currentNode->isEndOfWord; // Check if we have reached the end of the word and it's a valid word
        }

        char c = word[index];
        if (c == '.')
        {
            // If the current character is '.', we need to check all possible children nodes
            for (auto &child : currentNode->children)
            {
                if (searchHelper(word, index + 1, child.second))
                {
                    return true; // If any path returns true, we can return true
                }
            }
            return false; // If no path returns true, we return false
        }
        else
        {
            // If the current character is a specific letter, we check the corresponding child node
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                return false; // If the child node doesn't exist, return false
            }
            return searchHelper(word, index + 1, currentNode->children[c]); // Move to the child node and continue searching
        }
    }
};