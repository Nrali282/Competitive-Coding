

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.


    ***********************************************************
*/


#include <bits/stdc++.h>

// solution -1 : Brute Force

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0;
        int j = 0;
        for(int i=1;i<=2000;i++) {
            if(j<arr.size() && arr[j] == i)
                j++;
            else
                k--;
            if(k == 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

// solution -2 : Binary Search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0, end = n-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] - (mid + 1) < k)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start + k;
    }
};