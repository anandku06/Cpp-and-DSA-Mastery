// Reverse a Stack
// Difficulty: MediumAccuracy: 80.5%Submissions: 137K+Points: 4Average Time: 20m
// You are given a stack st[]. You have to reverse the stack.

// Note: The input array represents the stack from bottom to top (last element is the top). The output is displayed by printing elements from top to bottom after reversal.

// Examples:

// Input: st[] = [1, 2, 3, 4]
// Output: [1, 2, 3, 4]
// Explanation: After reversing, the elements of stack are in opposite order.

// Input: st[] = [3, 2, 1]
// Output: [3, 2, 1]
// Explanation: After reversing, the elements of stack are in opposite order.

// Constraints:
// 1 ≤ st.size() ≤ 100
// 0 ≤ stack element ≤ 100

// Approach: We can use recursion to reverse the stack. We will pop the top element of the stack and store it in a temporary variable. Then we will recursively call the reverse function on the remaining stack. After the recursive call, we will push the temporary variable back onto the stack. This way, we will reverse the order of the elements in the stack.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int topElement, stack<int> &st)
    {
        if (st.empty())
        {
            st.push(topElement); // Base case: If the stack is empty, push the top element back onto the stack
            return;
        }

        int temp = st.top(); // Store the top element of the stack
        st.pop();            // Remove the top element

        solve(topElement, st); // Recursively call solve with the stored top element

        st.push(temp); // Push the stored top element back onto the stack
    }

    void reverseStack(stack<int> &st)
    {
        if (st.empty())
        {
            return; // Base case: If the stack is empty, return
        }

        int topElement = st.top(); // Store the top element
        st.pop();                  // Remove the top element

        reverseStack(st); // Recursively reverse the remaining stack

        solve(topElement, st); // Push the stored top element back onto the stack
    }
};