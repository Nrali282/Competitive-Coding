

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
      const int dx[4]={-1,1,0,0};
      const int dy[4]={0,0,-1,1};
      
    //boundary checks
    bool  isValid(int i,int j,int r,int c){
          return (i<r && j<c && i>=0 && j>=0);
    }
 
    void changeIslandType(int i,int j,int r,int c,vector<vector<int>>& grid){

        if(i>=r || j>=c || i<0 || j<0 || grid[i][j]==0 || grid[i][j]==2)return;
        grid[i][j]=2;
        for(int x=0;x<4;++x){
            int nr=i+dx[x];
            int nc=j+dy[x];
            changeIslandType(nr,nc,r,c, grid);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
 
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
 
        int change=0;
        bool check=false;
        //change the islands
        for(int i=0;i<r;++i){

            for(int j=0;j<c;++j){

               if(grid[i][j]){
                   changeIslandType(i,j,r,c,grid);
                   check=true;
                   break;
               }
            }

            if(check)
            break;
        }
 
        //get the new islands in queue
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
               if(grid[i][j]==2){
                q.push({i,j});       
               }
            }
        }
 
 
        while(!q.empty()){
            change++;
         int sz=q.size();

            while(sz--){
               auto node=q.front();
               q.pop();
                //4 directions
               for(int x=0;x<4;++x){
                   int nr=node.first+dx[x];
                   int nc=node.second+dy[x];
 
                   if(isValid(nr,nc,r,c) ){
                       
                         if( grid[nr][nc]==0){
                             grid[nr][nc]=2;
                             q.push({nr,nc});
                         }

                         if(grid[nr][nc]==1)
                         return change-1; 
                   }  
               }     
            }
        }
 
       return 0; 
 
    }
};