// Celebrity Problem
// Difficulty: MediumAccuracy: 38.33%Submissions: 398K+Points: 4Average Time: 30m
// Consider a party being organized by some people. A celebrity is a person who is known to all but does not know anyone at the party.

// A square matrix mat[][] of size n * n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person.
// You need to return index of the celebrity in the party.
// If the celebrity does not exist, return -1.
// Note: Follow 0-based indexing.

// Examples:

// Input: mat[][] = [[1, 1, 0],
//                  [0, 1, 0],
//                  [0, 1, 1]]
// Output: 1
// Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.
// Input: mat[][] = [[1, 1],
//                  [1, 1]]
// Output: -1
// Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
// Input: mat[][] = [[1]]
// Output: 0
// Constraints:

// 1 ≤ mat.size(), mat[i].size() ≤ 103
// 0 ≤ mat[i][j] ≤ 1
// mat[i][i] = 1

// approach 1 -> brute force approach -> O(n^2) -> for each person, we will check if he knows anyone and if everyone knows him, if both conditions are satisfied, then he is the celebrity
// approach 2 -> using stack -> O(n) -> we will push all the people to the stack, then we will pop two people from the stack and check if one of them knows the other, if he does, then he cannot be the celebrity and we will push the other person back to the stack, if he does not know the other person, then he cannot be the celebrity and we will push the other person back to the stack, we will repeat this process until there is only one person left in the stack, then we will check if he is a celebrity or not by checking if he knows anyone and if everyone knows him.

#include <bits/stdc++.h>
using namespace std;

class Solution_1
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size(); // size of the matrix

        vector<int> knowMe(n, 0); // vector to store the number of people who know the ith person
        vector<int> iKnow(n, 0);  // vector to store the number of people whom the ith person knows

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1) // if the ith person knows the jth person
                {
                    knowMe[j]++; // increment the number of people who know the jth person
                    iKnow[i]++;  // increment the number of people whom the ith person knows
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (knowMe[i] == n - 1 && iKnow[i] == 0) // if the ith person is known by everyone and does not know anyone
            {
                return i; // return the index of the celebrity
            }
        }

        return -1; // if there is no celebrity, return -1
    }
};

// approach 2
class Solution_2
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size(); // size of the matrix
        stack<int> st;      // stack to store the people

        for (int i = 0; i < n; i++)
        {
            st.push(i); // push all the people to the stack
        }

        while (st.size() > 1) // while there is more than one person in the stack
        {
            int a = st.top(); // pop two people from the stack
            st.pop();
            int b = st.top();
            st.pop();

            if (mat[a][b] == 1) // if a knows b, then a cannot be the celebrity and we will push b back to the stack
            {
                st.push(b);
            }
            else // if a does not know b, then b cannot be the celebrity and we will push a back to the stack
            {
                st.push(a);
            }
        }

        int candidate = st.top(); // the last person left in the stack is the candidate for celebrity

        for (int i = 0; i < n; i++)
        {
            if (i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)) // check if the candidate knows anyone or if everyone knows him
            {
                return -1; // if he knows anyone or if everyone does not know him, then he is not a celebrity
            }
        }

        return candidate; // return the index of the celebrity
    }
};