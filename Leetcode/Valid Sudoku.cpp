

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:

https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char c){
        //row
        for(int j=0;j<=8;j++){
            if(board[row][j] == c)
                return  false; 
        }
        
        //col
        for(int i=0;i<=8;i++){
            if(board[i][col] == c)
                return false;
        }
       
        //grid
        int sr = (row/3)*3;
        int sc = (col/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j] == c)
                    return false;
            }
        }

        return true;
    }
    bool recur(vector<vector<char>>& board,int row,int col) {
        if(row==9 && col==0){
            return true;
        }

        int nextRow = row, nextCol = col + 1;
        if(col + 1 == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] == '.')
            return recur(board,nextRow,nextCol);
        
        char c = board[row][col];
        board[row][col] = '.';
        if(!isSafe(board,row,col,c)){
            return false;
        }
        board[row][col] = c;
        if(!recur(board,nextRow,nextCol))
            return false;

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return recur(board,0,0);
    }
};