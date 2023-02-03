

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:

https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:

https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:

https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

    ***********************************************************
*/


#include <bits/stdc++.h>

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) {
                ListNode* temp = head;
                while(temp!=fast) {
                    temp = temp->next;
                    fast = fast->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};