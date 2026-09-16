#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;

class StackUsingArrays
{
    int top = -1; 
    int stack[MAX_SIZE];

    public:
        void push(int x)
        {
            if(top >= MAX_SIZE) cout << "Stack Overflow" << endl;

            ++top;
            stack[top] = x;
        }

        int top()
        {
            return stack[top];
        }

        void pop()
        {
            if(top <= -1) cout << "Stack Underflow" << endl;

            --top;
        }

        int size()
        {
            return (top + 1);
        }
};