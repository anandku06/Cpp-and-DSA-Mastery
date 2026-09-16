#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

class Stack
{
    Node* top;
    int size = 0;

    public:
        void push(int x)
        {
            Node* temp = new Node(x);
            temp->next = top;
            top = temp;
            size++;
        }

        void pop()
        {
            Node* temp = top;
            top->next = top;
            delete temp;
            size--;
        }

        int top()
        {
            return (top->data);
        }

        int size()
        {
            return size;
        }
};
