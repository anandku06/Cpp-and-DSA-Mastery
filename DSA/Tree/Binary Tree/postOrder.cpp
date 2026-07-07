#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

void postOrderRecursive(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;

    postOrderRecursive(root->left, result);
    postOrderRecursive(root->right, result);
    result.push_back(root->data);
}

vector<int> postOrderTraversal(TreeNode *root)
{
    vector<int> postorder;
    if (root == nullptr)
        return postorder;

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left != nullptr)
            st1.push(root->left);

        if (root->right != nullptr)
            st1.push(root->right);
    }

    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
}