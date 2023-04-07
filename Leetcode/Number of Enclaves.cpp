

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
	
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:

https://assets.leetcode.com/uploads/2021/02/18/enclaves2.jpg
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    void bfs(int x,int y,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& vis) {
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y] = 1;

        vector<int> dirx{-1,0,0,1};
        vector<int> diry{0,-1,1,0};
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int r = x + dirx[i];
                int c = y + diry[i];

                if(r<0 || r>=m || c<0 || c>=n) {
                    continue;
                } else if(grid[r][c] == 1 && !vis[r][c]) {
                        q.push({r,c});
                        vis[r][c] = 1;
                }
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++) {
            if(grid[i][0] == 1 && !vis[i][0])
                bfs(i,0,m,n,grid,vis);

            if(grid[i][n-1] == 1 && !vis[i][n-1])
                bfs(i,n-1,m,n,grid,vis);
        }
        for(int i=0;i<n;i++) {
            if(grid[0][i] == 1 && !vis[0][i])
                bfs(0,i,m,n,grid,vis);

            if(grid[m-1][i] == 1 && !vis[m-1][i])
                bfs(m-1,i,m,n,grid,vis);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};