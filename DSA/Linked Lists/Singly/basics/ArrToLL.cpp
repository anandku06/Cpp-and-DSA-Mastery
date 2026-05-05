#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr){}
};

Node* convertToLL(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printLL(Node* head)
{
    Node* temp = head;

    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}

int main()
{
    vector<int> arr = {12, 4, 56, 7, 89};

    Node* head = convertToLL(arr);

    printLL(head);
    return 0;
}