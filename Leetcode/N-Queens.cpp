

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:

https://assets.leetcode.com/uploads/2020/11/13/queens.jpg
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<string> v,int row,int col){
        //vertically up
        for(int i=row-1;i>=0;i--){
            if(v[i][col]=='Q')
                return false;
        }

        //diag left up
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(v[i][j]=='Q')
                return false;
        }

        //diag right up
        for(int i=row-1,j=col+1;i>=0 && j<v.size();i--,j++){
            if(v[i][j]=='Q')
                return false;
        }
        return true;
    }
    void nQueens(vector<string> v,int i,int n) {
        if(i == n){
            res.push_back(v);
            return;
        }

        for(int j=0;j<n;j++){
            if(isSafe(v,i,j)){
                v[i][j]='Q';
                nQueens(v,i+1,n);
                v[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+='.';
            }
            v.push_back(s);
        }
        nQueens(v,0,n);
        return res;
    }
};