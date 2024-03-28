

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.

Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 0;
        
        unordered_map<int,vector<int>> indices;
        for(int i=0;i<n;i++) {
            indices[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n,false);
        q.push(0);
        vis[0] = true;
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int currIdx = q.front();
                q.pop();
                if(currIdx == n-1) {
                    return steps;
                }
                vector<int>& jumIndices = indices[arr[currIdx]];
                jumIndices.push_back(currIdx-1);
                jumIndices.push_back(currIdx+1);
                for(auto i : jumIndices) {
                    if(i>=0 && i<n && !vis[i]) {
                        q.push(i);
                        vis[i] = true;
                    }
                }
                jumIndices.clear();
            }
            steps++;
        }
        return -1;
    }
};