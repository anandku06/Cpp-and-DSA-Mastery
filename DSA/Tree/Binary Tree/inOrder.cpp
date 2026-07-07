#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inOrderRecursive(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;

    inOrderRecursive(root->left, result);
    result.push_back(root->data);
    inOrderRecursive(root->right, result);
}

vector<int> inOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    if (root == nullptr)
        return inorder;

    stack<TreeNode *> st;
    TreeNode *elem = root;

    while (true)
    {
        if (elem != nullptr)
        {
            st.push(elem);
            elem = elem->left;
        }
        else
        {
            if (st.empty())
                break;
            elem = st.top();
            st.pop();
            inorder.push_back(elem->data);
            elem = elem->right;
        }
    }

    return inorder;
}