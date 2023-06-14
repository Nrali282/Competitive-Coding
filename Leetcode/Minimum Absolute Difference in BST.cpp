

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

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
    vector<int> v;
    void traversal(TreeNode* root) {
        if(root == NULL)
            return;
        v.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        sort(v.begin(),v.end());
        int ans = INT_MAX;
        for(int i=0;i<v.size()-1;i++) {
            ans = min(ans, v[i+1]-v[i]);
        }
        return ans;
    }
};