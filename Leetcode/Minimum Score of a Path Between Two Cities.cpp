

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
 

Example 1:

https://assets.leetcode.com/uploads/2022/10/12/graph11.png
Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.

Example 2:

https://assets.leetcode.com/uploads/2022/10/12/graph22.png
Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int bfs(vector<vector<pair<int,int>>> adj,vector<int>& vis) {
        int res = INT_MAX;
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto i : adj[curr]) {
                res = min(res,i.second);
                if(!vis[i.first]) {
                    vis[i.first] = 1;
                    q.push(i.first);
                }
            }
        }
        return res;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i : roads) {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int> vis(n+1,0);
        return bfs(adj,vis);
    }
};