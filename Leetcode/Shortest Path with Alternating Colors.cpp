

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

 
Example 1:

Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]

Example 2:

Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n,-1);
        vector<vector<pair<int,int>>> adj(n);
        queue<vector<int>> q;
        vector<vector<bool>>visited(n, vector<bool>(2));
       
        for(auto r : redEdges) {
            adj[r[0]].push_back({r[1],0}); //0->red
        }
        for(auto b : blueEdges) {
            adj[b[0]].push_back({b[1],1}); // 1->blue
        }
        q.push({0,0,-1}); //node,steps,color
        visited[0][0]=true;
        visited[0][1]=true;
        res[0]=0;

        while(!q.empty()) {
            vector<int> temp = q.front();
            q.pop();
            int node=temp[0], steps=temp[1], prevColor=temp[2];

            for(auto [x,y] : adj[node]) {
                if(!visited[x][y] && prevColor != y) {
                    visited[x][y]=true;
                    q.push({x,1+steps,y});
                    if(res[x] == -1) {
                        res[x] = 1+steps;
                    }
                }
            }
        }
        return res;
    }
};