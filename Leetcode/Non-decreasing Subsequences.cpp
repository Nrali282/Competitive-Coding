

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

 

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
 

Constraints:

1 <= nums.length <= 15
-100 <= nums[i] <= 100

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    set<vector<int>> res;
    vector<int> temp;
    void func(int idx,vector<int>& nums) {
        int n=nums.size();

        if(idx==n){
            if(temp.size()>=2){
                res.insert(temp);
            }
            return ;
        }
       
        if(temp.empty() || nums[idx]>=temp.back()){
            temp.push_back(nums[idx]);
            func(idx+1,nums);
            temp.pop_back();
        }
        func(idx+1,nums); 
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        func(0,nums);
        return vector(res.begin(),res.end());
    }
};