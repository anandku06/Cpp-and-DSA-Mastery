// Sort a Linked List of 0's 1's and 2's
// Medium

// Hints
// Company
// Given the head of a singly linked list consisting of only 0, 1 or 2.

// Sort the given linked list and return the head of the modified list.

// Do it in-place by changing the links between the nodes without creating new nodes.

// Example 1

// Input: linkedList = [1, 0, 2, 0 , 1]

// Output: [0, 0, 1, 1, 2]

// Explanation: The values after sorting are [0, 0, 1, 1, 2].

// Example 2

// Input: linkedList = [1, 1, 1, 0]

// Output: [0, 1, 1, 1]

// Explanation: The values after sorting are [0, 1, 1, 1].

// Now your turn!

// Input: linkedList = [2, 2, 1, 2]

// Output:

// Correct

// [2, 2, 2, 1]

// [1, 2, 2, 2]

// [1, 2, 2]

// [2, 2, 1]
// Constraints

// 0 <= number of nodes in the Linked List <= 105
// 0 <= ListNode.val <= 2

// approach 1: Count the number of 0's, 1's and 2's in the linked list and then update the values of the nodes in the linked list according to the count of 0's, 1's and 2's.
// approach 2: Create three dummy nodes for 0's, 1's and 2's and then traverse the linked list and add the nodes to the corresponding dummy nodes. Finally, connect the three dummy nodes to get the sorted linked list.

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
    ListNode *sortList_1(ListNode *head)
    {
        ListNode *curr = head;    // pointer to traverse the linked list
        int count[3] = {0, 0, 0}; // array to store the count of 0's, 1's and 2's

        while (curr != nullptr)
        { // traverse the linked list and count the number of 0's, 1's and 2's
            count[curr->data]++;
            curr = curr->next;
        }

        curr = head; // pointer to traverse the linked list
        int i = 0;   // index to iterate through the count array

        while (curr != nullptr)
        { // traverse the linked list and update the values according to the count
            if (count[i] == 0)
            {
                i++;
                continue;
            }
            curr->data = i;
            count[i]--;
            curr = curr->next;
        }

        return head;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head; // if the linked list is empty or has only one node, then return the head

        ListNode *zeroHead = new ListNode(-1); // dummy node for 0's
        ListNode *oneHead = new ListNode(-1);  // dummy node for 1's
        ListNode *twoHead = new ListNode(-1);  // dummy node for 2's

        ListNode *zero = zeroHead; // pointer to traverse the 0's linked list
        ListNode *one = oneHead;   // pointer to traverse the 1's linked list
        ListNode *two = twoHead;   // pointer to traverse the 2's linked list

        ListNode *curr = head; // pointer to traverse the original linked list

        while (curr != nullptr)
        { // traverse the original linked list
            if (curr->data == 0)
            { // if the value of the current node is 0, then add it to the 0's linked list
                zero->next = curr;
                zero = zero->next;
            }
            else if (curr->data == 1)
            { // if the value of the current node is 1, then add it to the 1's linked list
                one->next = curr;
                one = one->next;
            }
            else
            { // if the value of the current node is 2, then add it to the 2's linked list
                two->next = curr;
                two = two->next;
            }
            curr = curr->next; // move to the next node of the original linked list
        }

        zero->next = (oneHead->next) ? oneHead->next : twoHead->next; // connect the 0's linked list to the 1's linked list if it exists, otherwise connect it to the 2's linked list
        one->next = twoHead->next;                                    // connect the 1's linked list to the 2's linked list
        two->next = nullptr;                                          // set the next pointer of the last node of the 2's linked list to nullptr

        return zeroHead->next; // return the head of the sorted linked list (which is the next node of zeroHead)
    }
};