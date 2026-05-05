// 143. Reorder List
// Medium
// Topics
// premium lock icon
// Companies
// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:

// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

// Constraints:

// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000

// Approach 1: Find middle of the linked list, reverse the second half of the linked list and then merge the two halves of the linked list

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        // find the middle of the linked list using the slow and fast pointer technique
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half of the linked list
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        while (curr != nullptr)
        {
            ListNode *nextTemp = curr->next; // store the next node
            curr->next = prev;               // reverse the current node's pointer
            prev = curr;                     // move prev to the current node
            curr = nextTemp;                 // move to the next node
        }

        // merge the two halves of the linked list
        ListNode *first = head;  // pointer for the first half
        ListNode *second = prev; // pointer for the second half (reversed)
        while (second->next != nullptr)
        {                                   // we can also check for first->next != nullptr, both will work since both halves will have same number of nodes or second half will have one less node than first half
            ListNode *temp1 = first->next;  // store the next node of first half
            ListNode *temp2 = second->next; // store the next node of second half

            first->next = second; // point first node to second node
            second->next = temp1; // point second node to the next node of first half

            first = temp1;  // move first pointer to the next node in first half
            second = temp2; // move second pointer to the next node in second half
        }
    }
};

// approach 2: using a stack to store the nodes of the linked list and then reorder the list by popping the nodes from the stack and rearranging the next pointers

class Solution2
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        stack<ListNode *> st; // stack to store the nodes of the linked list
        ListNode *curr = head;

        // push all nodes of the linked list onto the stack
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->next;
        }

        curr = head;           // pointer to traverse the linked list
        int k = st.size() / 2; // number of nodes to reorder, we only need to reorder the first half of the list

        // reorder the list by popping nodes from the stack and rearranging the next pointers
        while (k--)
        {
            ListNode *topNode = st.top(); // get the top node from the stack
            st.pop();                     // remove the top node from the stack

            ListNode *temp = curr->next; // store the next node of the current node
            curr->next = topNode;        // point the current node to the top node from the stack
            topNode->next = temp;        // point the top node from the stack to the next node of the current node

            curr = temp; // move the current pointer to the next node in the original list
        }

        curr->next = nullptr; // set the next pointer of the last node to nullptr to terminate the list
    }
};

// approach 3: Using recursion and backtracking

class Solution3
{
public:
    ListNode *curr; // pointer to traverse the linked list from the beginning

    void reorderListHelper(ListNode *head)
    {
        if (head == nullptr)
            return; // base case: if head is nullptr, return

        reorderListHelper(head->next); // recursive call to reorder the rest of the list

        ListNode *temp = curr->next; // store the next node of the current pointer
        if (temp == nullptr)
            return; // if temp is nullptr, it means we have reached the end of the list and we can stop reordering
        else if (head == curr)
        {
            head->next = nullptr; // if head is equal to curr, it means we have reached the middle of the list and we can stop reordering
            return;
        }

        curr->next = head;                          // point the current pointer to the head node
        head->next = temp == head ? nullptr : temp; // point the head node to the next node of the current pointer

        curr = temp; // move the current pointer to the next node in the original list
    }

    void reorderList(ListNode *head)
    {
        curr = head;             // pointer to traverse the linked list from the beginning
        reorderListHelper(head); // helper function to reorder the list using recursion and backtracking
    }
};