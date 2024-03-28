

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:

https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:

https://assets.leetcode.com/uploads/2021/08/10/balanced2-tree.jpg
Input: root = [2,1,3]
Output: [2,1,3]

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
    void getInorder(TreeNode* root, vector<int>& v) {
        if(root == NULL)
            return;

        getInorder(root->left,v);
        v.push_back(root->val);
        getInorder(root->right,v);
    }

    TreeNode* createBST(vector<int>& v, int start, int end) {
        if(start > end)
            return NULL;

        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = createBST(v,start,mid-1);
        root->right = createBST(v,mid+1,end);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        getInorder(root,v);

        return createBST(v,0,v.size()-1);
    }
};