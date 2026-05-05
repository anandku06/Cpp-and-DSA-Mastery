#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node* next;

    Node(int data) : value(data), next(nullptr){}
};

Node* deleteHead(Node* head)
{
    Node* temp = head;
    if(head == nullptr)
    return head;

    head = head->next;
    delete temp;

    return head;
}

Node* deleteEnd(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    return nullptr;

    Node* temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    
    return head;
}

Node* deleteAtK(Node* head, int k)
{
    if(head == nullptr) return nullptr;

    if(k == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr)
    {
        count++;

        if(count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node* deleteAnyNode(Node* head, int target)
{
    if(head == nullptr) return nullptr;

    if(head->value == target)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr)
    {
        if(temp->value == target)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    
    return head;
}