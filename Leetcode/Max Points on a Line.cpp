

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:
https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int max=1;
        float slope=0;
        unordered_map<float,int> mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(points[j][0]-points[i][0] == 0)
                    slope= 100000001;
                else
                    slope = (float)(points[j][1]-points[i][1]) / (float)(points[j][0]-points[i][0]);
                if(mp.find(slope) != mp.end())
                    mp[slope]++;
                else
                    mp.insert({slope,1});
            }
            for(auto i:mp){
                if(i.second+1 > max)
                    max=i.second+1;
            }
            mp.clear();
        }
        return max;
    }
};