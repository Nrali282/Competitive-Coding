

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    void quickSort(int i,int j,vector<int>& nums) {
        if(i>=j)
            return;

        int pIdx = partition(i,j,nums);
        quickSort(i,pIdx-1,nums);
        quickSort(pIdx+1,j,nums);
    }
    int partition(int si,int ei,vector<int>& nums) {
        int mid = si+(ei-si)/2;
        swap(nums[mid],nums[ei]);
        int pivot = nums[ei];
        int i = si-1;

        for(int j=si;j<ei;j++) {
            if(nums[j] <= pivot) {
                i++;
                int temp = nums[i];
                nums[i] =nums[j];
                nums[j] = temp;
            }
        }
        i++;
        int temp = nums[ei];
        nums[ei] = nums[i];
        nums[i]  = temp;
        return i;
    }
    vector<int> sortArray(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end()))
            return nums;
        quickSort(0,nums.size()-1,nums);
        return nums;
    }
};