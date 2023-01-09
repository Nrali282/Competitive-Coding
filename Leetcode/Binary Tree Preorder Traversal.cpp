

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> res;
    void preorder(TreeNode* root){
        res.push_back(root->val);
        if(root->left)
            preorder(root->left);
        if(root->right)
            preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return res;
        preorder(root);
        return res;
    }
};