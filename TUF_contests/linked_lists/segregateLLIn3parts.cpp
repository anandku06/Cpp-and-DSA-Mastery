// Segregate Nodes into 3 parts in LL
// Hard

// Given the head of a singly linked list, group all nodes based on the remainder when their indices are divided by 3 (i.e., indices % 3). Rearrange the list so that nodes with the same remainder are grouped together, and the groups appear in the order of increasing remainder values (0, 1, then 2). Return the head of the reordered linked list.

// Consider the 1st node to have index 1 and so on. The relative order of the elements inside each group must remain the same as the given input.

// Example 1

// Input: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6

// Output: head -> 3 -> 6 -> 1 -> 4 -> 2 -> 5

// Explanation:

// head -> 1(1) -> 2(2) -> 3(0) -> 4(1) -> 5(2) -> 6(0)

// In brackets, the value of index%3 is given. Ones with the same value are grouped together.

// head -> 3(0) -> 6(0) -> 1(1) -> 4(1) -> 2(2) -> 5(2)

// Example 2

// Input: head -> 6 -> 7 -> 3 -> 3 -> 7 -> 9 -> 1

// Output: head -> 3 -> 9 -> 6 -> 3 -> 1 -> 7 -> 7

// Explanation:

// head -> 6(1) -> 7(2) -> 3(0) -> 3(1) -> 7(2) -> 9(0) -> 1(1)

// In brackets, the value of index%3 is given. Ones with the same value are grouped together.

// head -> 3(0) -> 9(0) -> 6(1) -> 3(1) -> 1(1) -> 7(2) -> 7(2)

// Constraints

// 3 <= Number of nodes in the Linked List <= 105
// -104 <= ListNode.val <= 104

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
    ListNode *segregateNodes(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return head; // if the list has less than 3 nodes, return the head

        ListNode *zeroHead = new ListNode(0); // dummy node for remainder 0
        ListNode *oneHead = new ListNode(0);  // dummy node for remainder 1
        ListNode *twoHead = new ListNode(0);  // dummy node for remainder 2

        ListNode *zeroTail = zeroHead; // tail pointer for remainder 0
        ListNode *oneTail = oneHead;   // tail pointer for remainder 1
        ListNode *twoTail = twoHead;   // tail pointer for remainder 2

        int index = 1; // index of the current node

        while (head)
        {
            if (index % 3 == 0)
            {
                zeroTail->next = head; // add the current node to the remainder 0 list
                zeroTail = zeroTail->next;
            }
            else if (index % 3 == 1)
            {
                oneTail->next = head; // add the current node to the remainder 1 list
                oneTail = oneTail->next;
            }
            else
            {
                twoTail->next = head; // add the current node to the remainder 2 list
                twoTail = twoTail->next;
            }

            head = head->next; // move to the next node
            index++;           // increment the index
        }

        zeroTail->next = oneHead->next; // connect remainder 0 list to remainder 1 list
        oneTail->next = twoHead->next;  // connect remainder 1 list to remainder 2 list
        twoTail->next = nullptr;        // terminate the final list

        return zeroHead->next; // return the head of the reordered linked list
    }
};