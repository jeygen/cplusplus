/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
    }
};

class Solution {
public:

    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* tmp = head;

        while (tmp->next != nullptr) {
            if (tmp->val == INT_MAX) return true;
            tmp->val = INT_MAX;
            tmp = tmp->next;
        }
        
        return false;
    }
};

// chat gpt
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;

    ListNode *tortoise = head;
    ListNode *hare = head->next;

    while (tortoise != hare) {
        if (!hare || !hare->next) return false;
        tortoise = tortoise->next;
        hare = hare->next->next;
    }

    return true;
}

