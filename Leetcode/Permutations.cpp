

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& curr,vector<vector<int>>& res,vector<int>& nums) {
        if(curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for(int num : nums) {
            if(find(curr.begin(),curr.end(),num) == curr.end()) {
                curr.push_back(num);
                backtrack(curr,res,nums);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr = {};
        backtrack(curr, res, nums);
        return res;
    }
};