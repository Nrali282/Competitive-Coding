

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
	
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=1;i<n;i++) {
            grid[i][0] += grid[i-1][0];
        }
        for(int j=1;j<m;j++) {
            grid[0][j] += grid[0][j-1];
        }

        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};