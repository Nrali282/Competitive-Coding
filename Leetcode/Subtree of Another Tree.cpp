

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:

https://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:

https://assets.leetcode.com/uploads/2021/04/28/subtree2-tree.jpg
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
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
    bool isIdentical(TreeNode* node,TreeNode* subRoot) {
        if(node == NULL && subRoot == NULL)
            return true;
        else if(node == NULL || subRoot == NULL || node->val != subRoot->val)
            return false;

        if(!isIdentical(node->left,subRoot->left))
            return false;
        if(!isIdentical(node->right,subRoot->right))
            return false;
        
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)
            return false;

        if(root->val == subRoot->val) {
            if(isIdentical(root,subRoot))
                return true;
        }

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};