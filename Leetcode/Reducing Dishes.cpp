

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
	
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int helper(int idx, int time, vector<vector<int>>& dp,vector<int>& satisfaction) {
        if(idx == satisfaction.size())
            return 0;

        if(dp[idx][time] != -1)
            return dp[idx][time];

        return dp[idx][time] = max(satisfaction[idx]*time + helper(idx+1,time+1,dp,satisfaction),
        helper(idx+1,time,dp,satisfaction));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(satisfaction.size() + 1, vector<int>(satisfaction.size()+ 1, -1));
        return helper(0,1,dp,satisfaction);
    }
};