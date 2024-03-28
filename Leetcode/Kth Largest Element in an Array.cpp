

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,k);
    }

    int quickSelect(vector<int>& nums,int k) {
        int pivot = nums[rand() % nums.size()];

        vector<int> left;
        vector<int> mid;
        vector<int> right;

        for(int num : nums) {
            if(num > pivot)
                left.push_back(num);
            else if(num < pivot)
                right.push_back(num);
            else
                mid.push_back(num);
        }

        if(k <= left.size()) {
            return quickSelect(left,k);
        }

        if(left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }

        return pivot;
    }
};