// Add one to a number represented by LL
// Medium

// Hints
// Company
// Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.

// The number will contain no leading zeroes except when the value represented is zero itself.

// Example 1

// Input: head -> 1 -> 2 -> 3

// Output: head -> 1 -> 2 -> 4

// Explanation: The number represented by the linked list = 123.

// 123 + 1 = 124.

// Example 2

// Input: head -> 9 -> 9

// Output: head -> 1 -> 0 -> 0

// Explanation: The number represented by the linked list = 99.

// 99 + 1 = 100.

// Now your turn!

// Input: head -> 9

// Output: head -> 1 -> 0

// Correct

// head -> 1 -> 9

// head -> 1 -> 0

// head -> 9 -> 1

// head -> 8
// Constraints

// 0 <= number of nodes in the Linked List <= 105
// 0 <= ListNode.val <= 9
// No leading zeroes in the value represented.

// Approach: We can reverse the linked list, add one to the first node, and then reverse the linked list again to get the final result. If there is a carry after adding one, we can create a new node with value 1 and add it to the front of the linked list.

// Is it possible to solve the problem without reversing the linked list? Yes, we can use recursion to traverse the linked list and add one to the last node. If there is a carry, we can propagate it back to the previous nodes. If there is still a carry after processing all nodes, we can create a new node with value 1 and add it to the front of the linked list.

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
    ListNode *reverseALinkedList(ListNode *head)
    {
        if (!head || !head->next)
            return head; // if head is nullptr or there is only one node in the list, then return the head as it is

        ListNode *newHead = reverseALinkedList(head->next); // recursively reverse the rest of the list and get the new head of the reversed list

        head->next->next = head; // reversing the link to prev
        head->next = nullptr;    // updating the next of current node to nullptr

        return newHead; // returning the new head of the reversed list
    }

    ListNode *addOne(ListNode *head)
    {
        if (!head)
            return new ListNode(1); // if head is nullptr, then return a new node with value 1

        head = reverseALinkedList(head); // reverse the linked list

        ListNode *curr = head; // current pointer
        int carry = 1;         // initialize carry to 1

        while (curr)
        {
            int sum = curr->data + carry; // add carry to the current node's data
            curr->data = sum % 10;        // update the current node's data to sum % 10
            carry = sum / 10;             // update carry to sum / 10

            if (!curr->next && carry) // if we are at the last node and there is a carry, create a new node with value 1
            {
                curr->next = new ListNode(carry);
                break;
            }

            curr = curr->next; // move to the next node
        }

        head = reverseALinkedList(head); // reverse the linked list again to get the final result

        return head; // return the head of the final linked list
    }
};

class Solution2
{
public:
    int addOneHelper(ListNode *head)
    {
        if (!head)
            return 1; // if head is nullptr, return 1 as carry

        int carry = addOneHelper(head->next); // recursively call the function on the next node

        int sum = head->data + carry; // add carry to the current node's data
        head->data = sum % 10;        // update the current node's data to sum % 10
        return sum / 10;              // return carry for the previous node
    }

    ListNode *addOne(ListNode *head)
    {
        if (!head)
            return new ListNode(1); // if head is nullptr, then return a new node with value 1

        int carry = addOneHelper(head); // call the helper function to add one to the linked list

        if (carry) // if there is a carry after processing all nodes, create a new node with value 1 and add it to the front of the linked list
        {
            ListNode *newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }

        return head; // return the head of the final linked list
    }
};