#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr){}
};


int lengthOfLL(Node* root)
{
    int count = 0;
    if(root == nullptr) return count;

    Node* temp = root;
    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}