

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> memo;
    int minDistanceRec(string w1, string w2, int w1Idx, int w2Idx) {
        if(w1Idx==0)
            return w2Idx;
        if(w2Idx==0)
            return w1Idx;
        if (memo[w1Idx][w2Idx] != -1)
            return memo[w1Idx][w2Idx];
        int minDis = 0;
        if(w1[w1Idx-1] == w2[w2Idx-1])
            minDis = minDistanceRec(w1,w2,w1Idx-1,w2Idx-1);
        else {
            int insert = minDistanceRec(w1,w2,w1Idx,w2Idx-1);
            int delet = minDistanceRec(w1,w2,w1Idx-1,w2Idx);
            int replace = minDistanceRec(w1,w2,w1Idx-1,w2Idx-1);
            minDis = min(insert,min(delet,replace))+1;
        }
        memo[w1Idx][w2Idx] = minDis;
        return minDis;
    }
    int minDistance(string word1, string word2) {
        memo.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return minDistanceRec(word1,word2,word1.size(),word2.size());
    }
};