

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int LCS(string s1,string s2,int n,int m){
        int t[n+1][m+1];
        for(int i=0;i<m+1;i++){
            t[0][i]=0;
        }
        for(int i=0;i<n+1;i++){
            t[i][0]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
    int minInsertions(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.length();
        int lcs=LCS(s,s2,n,n);
        return n-lcs;
    }
};