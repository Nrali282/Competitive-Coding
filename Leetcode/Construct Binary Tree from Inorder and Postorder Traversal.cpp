

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:

https://assets.leetcode.com/uploads/2021/02/19/tree.jpg
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

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

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& mp, int& rootIdx, int left, int right) {
        if(left > right) return NULL;
        
        int pivot = mp[postorder[rootIdx]];
        TreeNode* node = new TreeNode(postorder[rootIdx]);
        rootIdx--;
        
        node->right = buildTreeHelper(inorder, postorder, mp, rootIdx, pivot+1, right);
        node->left = buildTreeHelper(inorder, postorder, mp, rootIdx, left, pivot-1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = postorder.size()-1;
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, mp, rootIdx, 0, inorder.size()-1);
    }
};