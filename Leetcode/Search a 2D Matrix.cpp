

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int start = 0;
        int end = (row * column) - 1;
        int mid;
        int element;

        while(start <= end) {
            mid = start + (end - start)/2;
            element = matrix[mid/column][mid%column];
            if(element == target)
                return true;
            else if(element < target)
                start = mid + 1;
            else if(element > target)
                end = mid - 1;
        }
        return false;
    }
};