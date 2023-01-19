

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:

https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startRow = 0, endRow=matrix.size()-1;
        int startCol = 0, endCol = matrix[0].size()-1;
        vector<int> res;
        while(startRow<=endRow && startCol<=endCol) {
            for(int i=startCol;i<=endCol;i++) {
                res.push_back(matrix[startRow][i]);
            }
            for(int i=startRow+1;i<=endRow;i++) {
                res.push_back(matrix[i][endCol]);
            }
            for(int i=endCol-1;i>=startCol;i--) {
                if(startRow == endRow)
                    break;
                res.push_back(matrix[endRow][i]);
            }
            for(int i=endRow-1;i>startRow;i--) {
                if(startCol == endCol)
                    break;
               res.push_back(matrix[i][startCol]);
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return res;
    }
};