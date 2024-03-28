

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:

https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
                result[n - layer - 1][ptr] = cnt++;
            }
            
            for (int ptr = n - layer - 2; ptr > layer; ptr--) {
                result[ptr][layer] = cnt++;
            }
        }

        return result;
    }
};