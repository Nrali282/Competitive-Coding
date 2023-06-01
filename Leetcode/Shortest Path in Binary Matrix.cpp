

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dist(n,vector<int> (n,0));

        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{-1,-1}, {-1,0}, {-1,1}, {0,1},
        {1,1}, {1,0}, {1,-1}, {0,-1}};

        q.push({0,0});
        dist[0][0] = 1;

        while(!q.empty()) {
            auto t = q.front();
            q.pop();

            int x = t.first;
            int y = t.second;
            
            for(auto i : dir) {
                int x1 = x + i[0];
                int y1 = y + i[1];

                if(x1 >= 0 && x1 < n  && y1 >= 0 && y1 < n && !grid[x1][y1] && !dist[x1][y1]) {
                    // if(x1 == n-1 && y1 == n-1)
                    //     return dist[x][y] + 1;
                    q.push({x1,y1});
                    dist[x1][y1] = dist[x][y] + 1;
                }
            }
        }
        if(dist[n-1][n-1] != 0)
            return dist[n-1][n-1];
        else
            return -1;
    }
};