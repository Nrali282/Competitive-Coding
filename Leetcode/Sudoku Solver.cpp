

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:

https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
Input: board = [["5","3",".",".","7",".",".",".","."],
				["6",".",".","1","9","5",".",".","."],
				[".","9","8",".",".",".",".","6","."],
				["8",".",".",".","6",".",".",".","3"],
				["4",".",".","8",".","3",".",".","1"],
				["7",".",".",".","2",".",".",".","6"],
				[".","6",".",".",".",".","2","8","."],
				[".",".",".","4","1","9",".",".","5"],
				[".",".",".",".","8",".",".","7","9"]]
				
Output: [["5","3","4","6","7","8","9","1","2"],
		 ["6","7","2","1","9","5","3","4","8"],
		 ["1","9","8","3","4","2","5","6","7"],
		 ["8","5","9","7","6","1","4","2","3"],
		 ["4","2","6","8","5","3","7","9","1"],
		 ["7","1","3","9","2","4","8","5","6"],
		 ["9","6","1","5","3","7","2","8","4"],
		 ["2","8","7","4","1","9","6","3","5"],
		 ["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png

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
    bool backtrack(vector<vector<char>>& board,int row,int col) {
        if(row==9 && col==0){
            return true;
        }

        int nextRow = row, nextCol = col + 1;
        if(col + 1 == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.')
            return backtrack(board,nextRow,nextCol);

        for(char i='1';i<='9';i++){
            if(isSafe(board,row,col,i)){
                board[row][col] = i;
                if(backtrack(board,nextRow,nextCol))
                    return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board,0,0);
    }
};