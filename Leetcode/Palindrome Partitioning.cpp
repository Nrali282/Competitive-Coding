

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 
Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;
    bool isPalindrome(string s,int startIdx, int endIdx) {
        while(startIdx <= endIdx) {
            if(s[startIdx] != s[endIdx])
                return false;
            startIdx++;
            endIdx--;
        }
        return true;
    }
    void palindromePartition(int idx,string s) {
        if(idx == s.size()) {
            res.push_back(temp);
            return;
        }

        for(int i=idx;i<s.size();i++) {
            if(isPalindrome(s,idx,i)) {
                temp.push_back(s.substr(idx, i-idx+1));
                palindromePartition(i+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        palindromePartition(0,s);
        return res;
    }
};