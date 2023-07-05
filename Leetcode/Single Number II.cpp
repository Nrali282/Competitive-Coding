

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,3,2]
Output: 3

Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums) {
            mp[x]++;
        }
        for(auto x: mp){
            if(x.second == 1){
                return x.first;
            }
        }
        return -1;
    }
};