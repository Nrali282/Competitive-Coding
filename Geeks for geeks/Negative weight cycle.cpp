

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.

Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3.

Example 2:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.

    ***********************************************************
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n,INT_MAX);
	    dist[0] = 0;
	    for(int i=0;i<n-1;i++) {
	        for(auto i : edges) {
	            if(dist[i[0]] != INT_MAX && dist[i[0]] + i[2] < dist[i[1]]) {
	                dist[i[1]] = dist[i[0]] + i[2];
	            }
	        }
	    }
	    
	    int flag = 0;
	    for(auto i : edges) {
            if(dist[i[0]] + i[2] < dist[i[1]]) {
                return 1;
            }
        }
        return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends