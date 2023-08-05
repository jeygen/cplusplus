/*
206. Reverse Linked List
Easy
18.9K
347
Companies

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    }
};



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseListHelper(head, nullptr);
    }
    
    ListNode* reverseListHelper(ListNode* current, ListNode* prev) {
        if (current == nullptr)  
            return prev;  // Base case: Return the new head.
        
        ListNode* nextNode = current->next;  // Save the next node.
        current->next = prev;  // Reverse the link.
        
        return reverseListHelper(nextNode, current);
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextNode = nullptr;
        
        while (current != nullptr) {
            nextNode = current->next;  // Save the next node.
            current->next = prev;  // Reverse the link.
            prev = current;  // Move the prev pointer forward.
            current = nextNode;  // Move the current pointer forward.
        }
        
        return prev;  // At the end, prev will be pointing to the new head of the reversed list.
    }
};

 
