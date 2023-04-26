

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Example 1:

https://assets.leetcode.com/uploads/2020/01/22/sample_1_1702.png
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Example 2:

https://assets.leetcode.com/uploads/2020/01/22/sample_2_1702.png
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

Example 3:

Input: root = [1]
Output: 0

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
    int length = 0;
    void dfs(TreeNode* root, bool goLeft, int steps) {
        if(root == NULL)
            return;
        
        length = max(length,steps);
        
        if(goLeft) {
            dfs(root->left,false, 1 + steps);
            dfs(root->right,true,1);
        } else {
            dfs(root->left,false,1);
            dfs(root->right,true, 1 + steps);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,false,0);
        dfs(root,true,0);
        return length;
    }
};