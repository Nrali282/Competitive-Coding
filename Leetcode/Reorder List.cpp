

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:

https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:

https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]


    ***********************************************************
*/


#include <bits/stdc++.h>

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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        //find mid
        ListNode* mid = findMid(head);

        //reverse 2nd half
        ListNode* curr = mid->next;
        mid->next = NULL;
        ListNode* prev = NULL;
        ListNode* next;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* left = head;
        ListNode* right = prev;
        ListNode* nextL,*nextR;

        //alternate merging
        while(left!=NULL && right!=NULL) {
            nextL = left->next;
            left->next = right;
            nextR = right->next;
            right->next = nextL;

            left = nextL;
            right = nextR;
        }
    }
};