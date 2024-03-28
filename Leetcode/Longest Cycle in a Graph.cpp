

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
	
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

Example 1:

https://assets.leetcode.com/uploads/2022/06/08/graph4drawio-5.png
Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.

Example 2:

https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-1.png
Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int ans = -1;
    void dfs(int node,vector<int>&edges,vector<bool>&vis,vector<bool>&dfsVis,vector<int>&dist,int distance){
        if(node!=-1){
            if(!vis[node]){
                vis[node]=true;
                dfsVis[node]=true;
                dist[node]=distance;
                dfs(edges[node],edges,vis,dfsVis,dist,distance+1);
            }
            else if(dfsVis[node]){
                ans=max(ans,distance-dist[node]);
            }
            dfsVis[node]=false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool>vis(n,false);
        vector<bool>dfsVis(n,false);
        vector<int>dist(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,edges,vis,dfsVis,dist,0);
            }
        }
        return ans;
    }
};