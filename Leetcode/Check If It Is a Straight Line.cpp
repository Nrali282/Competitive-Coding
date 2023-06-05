

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
Output: 3

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getYDiff(vector<int>& a, vector<int>& b) {
        return a[1] - b[1];
    }
    
    int getXDiff(vector<int>& a, vector<int>& b) {
        return a[0] - b[0];
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int deltaY = getYDiff(coordinates[1], coordinates[0]);
        int deltaX = getXDiff(coordinates[1], coordinates[0]);

        for (int i = 2; i < coordinates.size(); i++) {
            if (deltaY * getXDiff(coordinates[i], coordinates[0])
                != deltaX * getYDiff(coordinates[i], coordinates[0])) {
                return false;
            }
        }
        return true;
    }
};