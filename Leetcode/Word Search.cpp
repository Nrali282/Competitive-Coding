

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

    ***********************************************************
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int row, int col,int idx, vector<vector<char>>& board, string word) {
        if(idx == word.length()) 
            return true;

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() ||
        board[row][col] != word[idx]) {
                return false;
        }

        board[row][col] = '*';

        bool ans = dfs(row-1,col,idx+1,board,word) || 
                   dfs(row+1,col,idx+1,board,word) ||
                   dfs(row,col-1,idx+1,board,word) ||
                   dfs(row,col+1,idx+1,board,word);

        board[row][col] = word[idx];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i,j,0,board, word))
                        return true;
                }
            }
        }
        return false;
    }
};