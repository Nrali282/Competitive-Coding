

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
Output: 1389537

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void findSubsets(vector<int>& nums,int i) {
        if(i== nums.size()) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        findSubsets(nums,i+1);
        temp.pop_back();
        findSubsets(nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        findSubsets(nums,0);
        return res;
    }
};