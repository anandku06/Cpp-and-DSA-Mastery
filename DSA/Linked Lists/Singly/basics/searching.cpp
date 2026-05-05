#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr){}
};

bool searching(Node* head, int target)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        if(temp->data == target)
        {
            return true;
        }

        temp = temp->next;
    }

    return -1;
    
}