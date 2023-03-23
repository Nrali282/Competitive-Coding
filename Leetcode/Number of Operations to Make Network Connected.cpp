

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

Example 1:

https://assets.leetcode.com/uploads/2020/01/02/sample_1_1677.png
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:

https://assets.leetcode.com/uploads/2020/01/02/sample_2_1677.png
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis) {
        vis[node] = 1;
        for(auto i : adj[node]) {
            if(!vis[i]) {
                dfs(i,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1 > connections.size())
            return -1;
        
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int connectedComponents = 0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                connectedComponents++;
                dfs(i,adj,vis);
            }
        }
        return connectedComponents - 1;
    }
};