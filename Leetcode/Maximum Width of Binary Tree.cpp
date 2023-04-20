

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:

https://assets.leetcode.com/uploads/2021/05/03/width1-tree.jpg
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:

https://assets.leetcode.com/uploads/2022/03/14/maximum-width-of-binary-tree-v3.jpg
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:

https://assets.leetcode.com/uploads/2021/05/03/width3-tree.jpg
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

    ***********************************************************
*/


#include <bits/stdc++.h>
#define ll long long
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int max_width = 1;
        while(!q.empty()) {
            ll l_idx = q.front().second;
            ll r_idx = q.back().second;

            int size = q.size();

            for(int i=0;i<size;i++) {
                auto x = q.front();
                q.pop();

                int idx = x.second;
                if(x.first->left)
                    q.push({x.first->left,(ll)2*idx + 1});
                if(x.first->right)
                    q.push({x.first->right,(ll)2*idx + 2});
            }

            max_width = max(max_width,int(r_idx - l_idx + 1));
        }
        return max_width;
     }
};