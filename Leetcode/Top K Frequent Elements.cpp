

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int> res;

        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;
        for( auto i : mp)
        {
            pq.push(make_pair( i.second, i.first));
        }

        for( int i =0;i<k ; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};