// 990. Satisfiability of Equality Equations
// Medium
// Topics
// premium lock icon
// Companies
// You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

// Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

// Example 1:

// Input: equations = ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
// There is no way to assign the variables to satisfy both equations.
// Example 2:

// Input: equations = ["b==a","a==b"]
// Output: true
// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

// Constraints:

// 1 <= equations.length <= 500
// equations[i].length == 4
// equations[i][0] is a lowercase letter.
// equations[i][1] is either '=' or '!'.
// equations[i][2] is '='.
// equations[i][3] is a lowercase letter.

// approach: we can use union-find (disjoint set) to solve this problem. We will iterate through the equations and for each equation, we will check if it is an equality or an inequality. If it is an equality, we will union the two variables of the equation. If it is an inequality, we will check if the two variables of the equation belong to the same set. If they belong to the same set, then we have found a contradiction and we will return false. Otherwise, we will continue checking the next equations.

// Why using union-find (disjoint set) is a good approach for this problem?
// Union-find (disjoint set) is a data structure that helps to keep track of a collection of disjoint sets and supports two main operations: find and union. In this problem, we can use union-find to group variables that are equal to each other into the same set. When we encounter an equality equation, we can union the sets of the two variables. When we encounter an inequality equation, we can check if the two variables belong to the same set. If they do, it means there is a contradiction, and we can return false. This approach is efficient and straightforward for solving the problem of satisfiability of equations.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]); // path compression
        }
        return parent[u];
    }

    void unionSet(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
        // return true; // we successfully performed a union, we return true
    }

    bool equationsPossible(vector<string> &equations)
    {
        parent.resize(26);
        rank.resize(26, 0);

        for (int i = 0; i < 26; i++)
        {
            parent[i] = i; // initialize the parent of each variable to itself
        }

        for (string &e : equations)
        {
            int u = e[0] - 'a'; // get the index of the first variable
            int v = e[3] - 'a'; // get the index of the second variable

            if (e[1] == '=')
            {
                unionSet(u, v); // if it is an equality, we will union the two variables
            }
        }

        for (string &e : equations)
        {
            int u = e[0] - 'a'; // get the index of the first variable
            int v = e[3] - 'a'; // get the index of the second variable

            if (e[1] == '!')
            {
                if (find(u) == find(v)) // if it is an inequality, we will check if the two variables belong to the same set
                {
                    return false; // if they belong to the same set, then we have found a contradiction and we will return false
                }
            }
        }

        return true; // if we don't find any contradiction in the equations, we will return true
    }
};

/**
 * Why not checking the inequalities in the first loop?
 * We need to check the inequalities after we have processed all the equalities because the equalities can change the sets of the variables. If we check the inequalities before processing all the equalities, we might get a false negative because we haven't yet merged the sets of the variables that are supposed to be equal. By processing all the equalities first, we ensure that we have the correct sets for all variables before checking the inequalities for contradictions.
 */