

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:

https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg
Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        return head;
    }
};