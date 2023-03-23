

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

Example 1:

https://assets.leetcode.com/uploads/2021/08/14/validpath-ex1.png
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Example 2:

https://assets.leetcode.com/uploads/2021/08/14/validpath-ex2.png
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for (int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<int> vis(n,0);
        q.push(source);
        vis[source] = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int curr = q.front();
                q.pop();
                for(int i : adj[curr]) {
                    if(!vis[i]) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
        return vis[destination];
    }
};