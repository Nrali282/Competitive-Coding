

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

    ***********************************************************
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool checkCycle(int node, int parent, vector<int> adj[],vector<int>& vis,vector<int>& dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto i : adj[node]) {
            if(!vis[i]) {
                if(checkCycle(i,node,adj,vis,dfsVis))
                    return true;
            } else if(dfsVis[i])
                return true;
        }
        dfsVis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> dfsVis(V,0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(checkCycle(i,-1,adj,vis,dfsVis))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends