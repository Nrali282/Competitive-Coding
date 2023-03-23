

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
	
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Example 1:

https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:

https://assets.leetcode.com/uploads/2020/09/28/all_2.jpg
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(int src,int dest,vector<vector<int>>& graph) {
        temp.push_back(src);
        if(src == dest) {
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        for(auto i : graph[src]) {
            dfs(i,dest,graph);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> temp;
        dfs(0,n-1,graph);
        return res;
    }
};