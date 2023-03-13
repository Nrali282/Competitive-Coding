

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg
Input: root = [1,2,2,null,3,null,3]
Output: false

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
    bool isMirror(TreeNode* root1,TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL || root2 == NULL)
            return false;
        return (root1->val == root2->val) && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isMirror(root->left,root->right);
    }
};