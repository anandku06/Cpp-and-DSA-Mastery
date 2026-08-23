// 160. Intersection of Two Linked Lists
// Easy
// Topics
// premium lock icon
// Companies
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// For example, the following two linked lists begin to intersect at node c1:

// The test cases are generated such that there are no cycles anywhere in the entire linked structure.

// Note that the linked lists must retain their original structure after the function returns.

// Custom Judge:

// The inputs to the judge are given as follows (your program is not given these inputs):

// intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
// listA - The first linked list.
// listB - The second linked list.
// skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
// skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
// The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

// Example 1:

// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
// Output: Intersected at '8'
// Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
// From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
// - Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
// Example 2:

// Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
// Output: Intersected at '2'
// Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
// From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
// Example 3:

// Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
// Output: No intersection
// Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
// Explanation: The two lists do not intersect, so return null.

// Constraints:

// The number of nodes of listA is in the m.
// The number of nodes of listB is in the n.
// 1 <= m, n <= 3 * 104
// 1 <= Node.val <= 105
// 0 <= skipA <= m
// 0 <= skipB <= n
// intersectVal is 0 if listA and listB do not intersect.
// intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.

// Follow up: Could you write a solution that runs in O(m + n) time and use only O(1) memory?

// approach: Brute force approach is to use two nested loops to check each node of listA with each node of listB. If we find a match, we return that node. If we reach the end of both lists without finding a match, we return null. This approach has a time complexity of O(m * n) and a space complexity of O(1).

// approach: We can use a hash set to store the nodes of listA. Then we can iterate through listB and check if any node is in the hash set. If we find a match, we return that node. If we reach the end of listB without finding a match, we return null. This approach has a time complexity of O(m + n) and a space complexity of O(m).

// approach: We can use two pointers to traverse both lists. We can initialize two pointers, one for each list. We can move both pointers forward one node at a time. When a pointer reaches the end of its list, we can redirect it to the head of the other list. If the two lists intersect, the pointers will meet at the intersection node after at most m + n steps. If the two lists do not intersect, the pointers will both reach the end (null) after at most m + n steps. This approach has a time complexity of O(m + n) and a space complexity of O(1).

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
    // brute force approach
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *currA = headA;
        while (currA)
        {
            ListNode *currB = headB;
            while (currB)
            {
                if (currA == currB)
                    return currA;
                currB = currB->next;
            }
            currA = currA->next;
        }
        return nullptr;
    }

    // hash set approach
    ListNode *getIntersectionNodeHashSet(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> chk;
        ListNode *temp = headA;

        while (temp)
        {
            chk.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while (temp)
        {
            if (chk.find(temp) != chk.end())
                return temp;
            temp = temp->next;
        }

        return nullptr;
    }

    // two pointer approach
    ListNode *getIntersectionNodeTwoPointer(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        while (ptrA != ptrB)
        {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }

        return ptrA;
    }
};