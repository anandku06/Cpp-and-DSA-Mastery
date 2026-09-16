#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};


class QueueUsingLL
{
    Node* start;
    Node* end;
    int size = 0;

    public:
        void push(int x)
        {
            Node* newNode = new Node(x);
            if(start == nullptr)
            {
                start = newNode;
                end = newNode;
            }

            end->next = newNode;
            end = newNode;
            size++;
        }

        int pop()
        {
            if(start == nullptr) cout << "Queue is empty" << endl;

            int poppedElem = start->data;
            Node* temp = start;
            start = start->next;
            delete temp;

            size--;
            return poppedElem;
        }

        int size()
        {
            return size;
        }

        int top()
        {
            return start->data;
        }
};