

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

Example 1:

https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:

https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

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
    int res = 0;
    int calculateSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        sum = sum *10 + root->val;
        if(root->left == NULL && root->right == NULL)
            return sum;
        int leftSum = calculateSum(root->left,sum);
        int rightSum = calculateSum(root->right,sum);
        return leftSum + rightSum;
    }
    int sumNumbers(TreeNode* root) {
        return calculateSum(root,0);
    }
};