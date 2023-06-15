

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

Example 1:

Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2

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
    int max_val = INT_MIN;
    int ans;
    int maxLevelSum(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
       // v.push_back(root->val);
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            while(size--) {
                auto x = q.front();
                q.pop();
                sum += x->val;
                if(x->left != NULL) {
                    q.push(x->left);
                    //sum += x->left->val;
                }
                if(x->right != NULL) {
                    q.push(x->right);
                    //sum += x->right->val;
                }
            }
            v.push_back(sum);
        }

        //v.pop_back();

        for(int i=0;i<v.size();i++) {
            if(max_val < v[i]) {
                max_val = v[i];
                ans = i+1;
            }
        }
        return ans;
    }
};