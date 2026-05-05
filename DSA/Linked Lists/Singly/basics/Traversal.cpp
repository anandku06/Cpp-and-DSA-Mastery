#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) : data(x), next (nullptr){}
};


void traversal(Node* root)
{
    Node* temp = root;

    if(root == nullptr)
    return;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}
