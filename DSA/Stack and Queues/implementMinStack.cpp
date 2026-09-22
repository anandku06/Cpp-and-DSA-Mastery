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
// void push(int value) pushes the element value onto the stack.
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

// approach: Using two stacks
// Intuition
// We can use two stacks to keep track of the elements and the minimum elements. The first stack will store all the elements, while the second stack will store the minimum elements. When we push a new element onto the stack, we compare it with the current minimum (the top of the second stack). If the new element is smaller than or equal to the current minimum, we also push it onto the second stack. When we pop an element from the first stack, if it is equal to the top of the second stack, we also pop it from the second stack. This way, we can always retrieve the minimum element in constant time.

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> st; // pair<value, current_min>

    MinStack()
    {
    }

    void push(int value)
    {
        if (st.empty())
        {
            st.push({value, value});
        }
        else
        {
            int current_min = min(value, st.top().second);
            st.push({value, current_min});
        }
    }

    void pop()
    {
        if (!st.empty())
        {
            st.pop();
        }
    }

    int top()
    {
        if (!st.empty())
        {
            return st.top().first;
        }
        return -1; // or throw an exception
    }

    int getMin()
    {
        if (!st.empty())
        {
            return st.top().second;
        }
        return -1; // or throw an exception
    }
};