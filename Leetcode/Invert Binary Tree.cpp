

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the root of a binary tree, invert the tree, and return its root.

Example 1:

https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []


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
    TreeNode* invertTree(TreeNode* root) {
    if (!root)
        return root;
        
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);
    return root;
    }
};