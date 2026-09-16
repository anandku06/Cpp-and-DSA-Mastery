#include <bits/stdc++.h>
using namespace std;

class QueueImplementation
{
    int currSize = 0, size = 5, start, end = -1;
    int q[size];

    public:
        void push(int x)
        {
            if(currSize == size)
            cout << "Queue is Full" << endl;

            if(currSize == 0)
            {
                start = end = 0;
            }

            else end = (end + 1) % size;

            q[end] = x;
            currSize++;
        }

        int pop()
        {
            if(currSize == 0)
            cout << "Queue is empty" << endl;
            int ele = q[start];

            if(currSize == 1)
            {
                start = end = -1;
            }
            else start = (start + 1) % size;

            currSize--;
            return ele;
        }

        int top()
        {
            if(currSize == 0)
            {
                cout << "Queue is empty" << endl;
            }

            return q[start];
        }

        int Size()
        {
            return currSize;
        }
};