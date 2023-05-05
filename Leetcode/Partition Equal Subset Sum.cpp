

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise. 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }

        if(sum % 2 != 0)
            return false;
        sum /= 2;
        int n = nums.size();
        bool dp[n+1][sum+1];

        for(int i=0;i<sum+1;i++) {
            dp[0][i] = false;
        }

        for(int i=0;i<n+1;i++) {
            dp[i][0] = true;
        }

        for(int i=1;i<n+1;i++) {
            for(int j=1;j<sum+1;j++) {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][sum];
    }
};