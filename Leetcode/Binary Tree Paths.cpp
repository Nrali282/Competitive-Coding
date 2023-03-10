

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:

https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:

Input: root = [1]
Output: ["1"]

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
    vector<int> temp;
    vector<vector<int>> ans;
    void paths(TreeNode* root) {
        if(root == NULL)
            return;
        temp.push_back(root->val);
        if(root->left == NULL && root->right==NULL)
            ans.push_back(temp);
        paths(root->left);
        paths(root->right);
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        paths(root);
        vector<string> res;
        for(auto v : ans) {
            string s = "";
            for(int j=0;j<v.size()-1;j++) {
                s += to_string(v[j]);
                s += "->";
            }
            s += to_string(v[v.size()-1]);
            res.push_back(s);
        }
        return res;
    }
};