

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
	
You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

Example 1:

https://assets.leetcode.com/uploads/2022/05/05/tc-3.png
Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

Example 2:

https://assets.leetcode.com/uploads/2022/05/05/tc-2.png
Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int dfs(int node,vector<vector<int>>& adj,vector<int>& vis) {
        int count = 1;
        vis[node] = 1;
        for(auto i : adj[node]) {
            if(!vis[i]) {
                count += dfs(i,adj,vis);
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        long long numberOfPairs = 0;
        long long sizeOfComponent = 0;
        long long remainingNodes = n;

        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                sizeOfComponent = dfs(i,adj,vis);
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        return numberOfPairs;
    }
};