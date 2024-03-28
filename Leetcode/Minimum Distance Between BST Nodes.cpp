

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Example 1:

https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg
Input: root = [4,2,6,1,3]
Output: 1

Example 2:

https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg
Input: root = [1,0,48,null,null,12,49]
Output: 1


    ***********************************************************
*/


#include <bits/stdc++.h>

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
    vector<int> v;
    void inOrder(TreeNode* root) {
        if(root == NULL)
            return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        int minimum = INT_MAX;
        for(int i=0;i<v.size()-1;i++) {
            minimum = min(minimum,abs(v[i]-v[i+1]));
        }
        return minimum;
    }
};