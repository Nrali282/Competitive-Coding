

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(grid[i][j] >= 0) {
                    break;
                }
                res++;
            }
        }

        return res;
    }
};