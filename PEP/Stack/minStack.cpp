// 155. Min Stack
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

// Constraints:

// -231 <= val <= 231 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 104 calls will be made to push, pop, top, and getMin.

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> st; // as we need ops in constant time, so using stack with pairs (hashmap logic)
    // first will manage the stack order and second will manage the minimum value

    MinStack()
    {
    }

    void push(int val)
    {
        // if stack is empty then store the value as it is
        if (st.empty()) 
        {
            st.push({val, val});
            return;
        }

        // else get the minimum from the stack and push it in the stack
        int mini = min(getMin(), val);
        st.push({val, mini});
    }

    void pop()
    {
        return st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */