

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example 1:

https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Example 2:

https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-2.png
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.

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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        bool nullNode = false;
        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode == NULL)
                nullNode = true;
            else {
                if(nullNode)
                    return false;
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return true;
    }
};