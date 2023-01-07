

/* 
    Solution by Nirali Rathod
    
    ***********************************************************


You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int res=0;

        for(int i:tasks){
            mp[i]++;
        }

        for(auto i:mp){
            if(i.second==1){
                return -1;
            }
            if(i.second%3==0)
                res+= i.second/3;
            else
                res+=i.second/3 + 1;
        }
        return res;
    }
};