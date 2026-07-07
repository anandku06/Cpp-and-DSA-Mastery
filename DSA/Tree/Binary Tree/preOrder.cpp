#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int c) : data(c), left(nullptr), right(nullptr) {}
};

void preOrderRecursive(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;

    result.push_back(root->data);
    preOrderRecursive(root->left, result);
    preOrderRecursive(root->right, result);
}

vector<int> preOrderIterative(TreeNode *root)
{
    vector<int> result;

    if (root == nullptr)
        return result;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        result.push_back(root->data);

        if (root->right != nullptr)
            st.push(root->right);

        if (root->left != nullptr)
            st.push(root->left);
    }

    return result;
}