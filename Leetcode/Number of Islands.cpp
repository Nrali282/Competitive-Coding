

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]

Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

Output: 3
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, int n, int m) {
        queue<pair<int,int>> q;
        q.push({row, col});
        grid[row][col] = '0';

        vector<int> x = {0,0,1,-1};
        vector<int> y = {1,-1,0,0};

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int x1 = p.first;
            int y1 = p.second;

            for(int i=0;i<4;i++) {
                int x2 = x1 + x[i];
                int y2 = y1 + y[i];

                if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && grid[x2][y2] == '1') {
                    q.push({x2,y2});
                    grid[x2][y2] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    bfs(i, j, grid, n, m);
                    count++;
                }
            }
        }

        return count;
    }
};