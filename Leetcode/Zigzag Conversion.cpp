

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        bool down = true;
        vector<string> v(numRows);

        for(int i=0,j=0;i<s.length();i++) {
            v[j].push_back(s[i]);
            if(down) {
                if(j == numRows-1) {
                    j--;
                    down = false;
                } else {
                    j++;
                }
            } else {
                if(j==0) {
                    j++;
                    down = true;
                } else {
                    j--;
                }
            }
        }
        string ans;
        for(int i=0;i<v.size();i++){
            ans += v[i];
        }
        return ans;
    }
};