

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:

Input: nums = [1], target = 1
Output: 1

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int subsetsum(vector<int> nums,int sum){
        int n=nums.size();
        int t[n+1][sum+1];
        for(int i=0;i<sum+1;i++){
            t[0][i]=0;
        }
        t[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]] + t[i-1][j];
                } else {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if((sum+target)%2 != 0 || (sum+target)<0){
            return 0;
        }
        int targetsum = (sum+target)/2;
        return subsetsum(nums,targetsum);
    }
};