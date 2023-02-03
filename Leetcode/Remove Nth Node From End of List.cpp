

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:

https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

    ***********************************************************
*/


 // Solution 1
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
 #include <bits/stdc++.h>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        
        ListNode *temp1,*temp2;
        temp1 = temp2 = newHead;
        
        while(n--){
            temp2=temp2->next;
        }
        
        while(temp2->next){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        temp1->next = temp1->next->next;
        
        return newHead->next;
    }
};

//Solution 2
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
 #include <bits/stdc++.h>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int size = 0;

        while(temp1 != NULL) {
            temp1 = temp1->next;
            size++;
        }
        
        if(n == size) {
            head = head->next;
            return head;
        }

        int i=1;
        int find = size - n;

        while(i!=find){
            temp2 = temp2->next;
            i++;
        }

        temp2->next = temp2->next->next;
        return head;
    }
};