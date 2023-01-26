

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:

https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:

https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:

https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:flights) {
            adj[i[0]].push_back({i[1],i[2]});
        }

        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> minCost(n,INT_MAX);
        int stops=0;
        while(!q.empty() && stops<=k) {
            int size=q.size();
            while(size--){
                auto [currnode,price] = q.front();
                q.pop();
                for(auto [x,y] : adj[currnode]) {
                    if(price + y < minCost[x]) {
                        minCost[x] = price + y;
                        q.push({x,minCost[x]});
                    }
                }
            }
            stops++;
        }

        if(minCost[dst] == INT_MAX)
            return -1;
        
        return minCost[dst];
    }
};