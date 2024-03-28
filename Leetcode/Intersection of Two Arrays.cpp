

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(auto i:nums1) {
            if(count(nums2.begin(),nums2.end(),i) > 0) {
                if(count(res.begin(),res.end(),i) == 0) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};