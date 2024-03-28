

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int i = 0;
        int j = nums.size()-1;
        while(i<j) {
            int mid = (i+j)/2;
            if(mid % 2 == 1)
                mid--;
            if(nums[mid] != nums[mid+1])
                j = mid;
            else
                i = mid +2; 
        }
        return nums[i];
    }
};