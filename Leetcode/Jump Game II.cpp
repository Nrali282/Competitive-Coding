

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int solve(int index, int n, vector<int>& arr,vector<int>& dp)
    {
        if(index == n ) return 0;
        if(dp[index] != -1) return dp[index];
        int minStep = 1e9;
        for(int i=1; i<= arr[index]; i++)
        {
            if(index + i <= n)
            {
                int curr = 1 + solve(index+i, n, arr,dp);
                minStep = min(minStep, curr);
            }
        }

        return dp[index] = minStep;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n-1, nums,dp);
    }
};