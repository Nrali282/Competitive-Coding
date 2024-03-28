

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.


Example 1:

https://assets.leetcode.com/uploads/2019/05/03/1336_ex1.JPG
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

Example 2:

https://assets.leetcode.com/uploads/2019/05/03/1336_ex2.JPG
Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        vector<vector<int>> visited = grid;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(visited[i][j] == 1)
                    q.push({i,j});
            }
        }
        if(q.empty() || q.size()==n*n)
            return -1;
        
        int dis = -1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto[x,y] = q.front();
                q.pop();
                for(auto [dx,dy] : dirs) {
                    int i = x+dx, j = y+dy;
                    if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == 0) {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            dis++;
        }
        return dis;
    }
};