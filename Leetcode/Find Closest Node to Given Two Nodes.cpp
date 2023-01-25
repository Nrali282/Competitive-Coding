

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.

 

Example 1:

https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-2.png
Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.

Example 2:

https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-4.png
Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
 

Constraints:

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i
0 <= node1, node2 < n

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> dist1;
    vector<int> dist2;
    void bfs(vector<int>& edges, int node1, int node2) {
        queue<int> q;
        q.push(node1);
        dist1[node1]=0;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(edges[x] != -1) {
                if(dist1[edges[x]] == -1) {
                    dist1[edges[x]] = dist1[x]+1;
                    q.push(edges[x]);
                }
            }
        }

        q.push(node2);
        dist2[node2]=0;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(edges[x] != -1) {
                if(dist2[edges[x]] == -1) {
                    dist2[edges[x]] = dist2[x]+1;
                    q.push(edges[x]);
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        dist1.resize(n,-1);
        dist2.resize(n,-1);

        bfs(edges,node1,node2);

        int minDist = INT_MAX;
        int minNode = -1;

        for(int i=0;i<n;i++) {
            if(dist1[i]!= -1 && dist2[i]!=-1) {
                int maxDist = max(dist1[i],dist2[i]);
                if(maxDist < minDist) {
                    minDist = maxDist;
                    minNode = i;
                }
            }
        }
        return minNode;
    }
};