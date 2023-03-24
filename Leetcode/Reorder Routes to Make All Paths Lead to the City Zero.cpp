

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
	
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

Example 1:

https://assets.leetcode.com/uploads/2020/05/13/sample_1_1819.png
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:

https://assets.leetcode.com/uploads/2020/05/13/sample_2_1819.png
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int dfs(int node,vector<vector<int>>& adj, vector<int>& vis) {
        int res = 0;
        vis[node] = 1;
        for(auto i : adj[abs(node)]) {
            if(!vis[abs(i)]) {
                res += dfs(abs(i),adj,vis) + (i > 0);
            }
        }
        return res;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(-i[0]);
        }
        return dfs(0,adj,vis);
    }
};