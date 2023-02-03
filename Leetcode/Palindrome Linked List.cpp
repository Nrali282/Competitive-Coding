

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the head of a singly linked list, return true if it is a palindrome or false otherwise. 

Example 1:

https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg
Input: head = [1,2,2,1]
Output: true

Example 2:

https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg
Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

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
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;

        //find mid
        ListNode* mid = findMid(head);

        //reverse 2nd half
        ListNode* prev = NULL;
        ListNode* curr = mid;
        ListNode* next;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* right = prev;
        ListNode* left = head;

        //check 1st half & 2nd half
        while(right != NULL) {
            if(left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};