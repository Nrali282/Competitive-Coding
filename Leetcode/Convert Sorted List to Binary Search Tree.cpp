

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Example 1:

https://assets.leetcode.com/uploads/2020/08/17/linked.jpg
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBST(vector<int>& v,int start,int end) {
        if(start > end)
            return NULL;
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = createBST(v,start,mid-1);
        root->right = createBST(v,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        return createBST(v,0,v.size()-1);
    }
};