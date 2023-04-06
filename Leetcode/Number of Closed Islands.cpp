

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
	
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Example 1:

https://assets.leetcode.com/uploads/2019/10/31/sample_3_1610.png
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:

https://assets.leetcode.com/uploads/2019/10/31/sample_4_1610.png
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool bfs(int x, int y, int m,int n,vector<vector<int>>& grid,vector<vector<int>>& vis) {
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y] = 1;
        bool isClosed = true;

        vector<int> dirx{0,1,0,-1};
        vector<int> diry{-1,0,1,0};

        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = x + dirx[i];
                int c = y + diry[i];
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    isClosed = false;
                } else if (grid[r][c] == 0 && !vis[r][c]) {
                    q.push({r, c});
                    vis[r][c] = true;
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0 && !vis[i][j] && bfs(i,j,m,n,grid,vis))
                    count++;
            }
        }
        return count;
    }
};