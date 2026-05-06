// 2. Add Two Numbers
// Medium
// Topics
// premium lock icon
// Companies
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

struct ListNode
{
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int val) : data(val), next(nullptr) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2; // if l1 is nullptr, then return l2
        if (l2 == nullptr)
            return l1; // if l2 is nullptr, then return l1

        ListNode *dummy = new ListNode(); // dummy node to store the head of the result linked list
        ListNode *curr = dummy;           // pointer to traverse the result linked list
        int carry = 0;                    // variable to store the carry value

        // traverse both linked lists until we reach the end of both linked lists 
        while (l1 != nullptr || l2 != nullptr)
        {
            int sum = carry; // initialize sum with the carry value

            if (l1 != nullptr)
            { // if l1 is not nullptr, then add the value of the current node of l1 to sum and move to the next node of l1
                sum += l1->data;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            { // if l2 is not nullptr, then add the value of the current node of l2 to sum and move to the next node of l2
                sum += l2->data;
                l2 = l2->next;
            }

            carry = sum / 10;                    // update carry value for the next iteration
            curr->next = new ListNode(sum % 10); // create a new node with the last digit of sum and point the next pointer of curr to this new node
            curr = curr->next;                   // move curr pointer to the next node in the result linked list
        }

        if (carry > 0)
        { // if there is a carry value left after processing both linked lists, then create a new node with this carry value and point the next pointer of curr to this new node
            curr->next = new ListNode(carry);
        }

        return dummy->next; // return the head of the result linked list (which is the next node of dummy)
    }
};