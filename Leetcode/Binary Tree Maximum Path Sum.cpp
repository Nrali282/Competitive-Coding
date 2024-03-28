

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:

https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:

https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.


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
    int res = INT_MIN;
    int cal(TreeNode* root) {
        if(root == NULL)
            return -10001;
        
        int leftSum = cal(root->left);
        int rightSum = cal(root->right);

        int temp = max(max(leftSum,rightSum)+root->val,root->val);
        int maximum = max(temp, leftSum + rightSum + root->val);
        res = max(res,maximum);

        return temp;
    }
    int maxPathSum(TreeNode* root) {
        cal(root);
        return res;
    }
};