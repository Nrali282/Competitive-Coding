

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

Example 1:

https://assets.leetcode.com/uploads/2020/08/16/e1.jpg
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:

https://assets.leetcode.com/uploads/2020/08/16/e2.jpg
Input: root = [2,1,1]
Output: [[1]]

Example 3:

https://assets.leetcode.com/uploads/2020/08/16/e33.jpg
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]


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
    unordered_map<string,int> mp;
    vector<TreeNode*> v;
    string postOrder(TreeNode* root) {
        if(!root)
            return "";

        string left = postOrder(root->left);
        string right = postOrder(root->right);

        string s = to_string(root->val) + " " + left + " " + right;

        if(mp[s] == 1)
            v.push_back(root);
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        postOrder(root);
        return v;
    }
};