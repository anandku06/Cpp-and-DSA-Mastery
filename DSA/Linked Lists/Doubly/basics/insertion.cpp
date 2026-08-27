#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;


    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node*& head, int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;

    if(head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node*& head, int data, int position) {
    if (position == 0) {
        insertAtHead(head, data);
        return;
    }
    
    Node* newNode = new Node(data);
    Node* temp = head;
    
    for (int i = 1; i <= position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }
    
    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}
