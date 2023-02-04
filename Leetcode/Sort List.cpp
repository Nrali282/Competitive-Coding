

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:

https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next!= NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head) {
        //base
        if(head == NULL || head->next == NULL)
            return head;

        //find mid
        ListNode* mid = findMid(head);

        ListNode* rightHead = mid->next;
        mid->next = NULL;

        ListNode* node1 = mergeSort(head);
        ListNode* node2 = mergeSort(rightHead);

        return merge(node1,node2);
    }
    ListNode* merge(ListNode* node1,ListNode* node2) {
        ListNode* mergell = new ListNode(-1);
        ListNode* temp = mergell;

        while(node1!=NULL && node2!=NULL) {
            if(node1->val <= node2->val) {
                temp->next = node1;
                node1 = node1->next;
                temp = temp->next;
            } else {
                temp->next = node2;
                node2 = node2->next;
                temp = temp->next;
            }
        }

        while(node1 != NULL){
            temp->next = node1;
            node1 = node1->next;
            temp = temp->next;
        }

        while(node2 != NULL){
            temp->next = node2;
            node2 = node2->next;
            temp = temp->next;
        }

        return mergell->next;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};