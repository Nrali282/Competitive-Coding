

/* 
    Solution by Nirali Rathod
    
    ***********************************************************


You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:

abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int delete_col = 0;
        int row = strs.size();
        int col = strs[0].size();

        for(int i=0;i<col;i++){
            for(int j=0;j<row-1;j++){
                if(strs[j][i]>strs[j+1][i]){
                    delete_col++;
                    break;
                }
            }
        }

        return delete_col;
    }
};