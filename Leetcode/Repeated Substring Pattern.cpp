

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

//Solution - 1

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = 1; i <= n/2; i++) {
            if(n % i == 0) {
                string substring = s.substr(0,i);
                string repeated = "";
                for(int j = 0; j < n/i; j++) {
                    repeated += substring;
                }
                if(repeated == s)
                    return true;
            }
        }
        return false;
    }
};

// Solution - 2

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = s + s;
        if(str.substr(1,str.size()-2).find(s) != string::npos)
            return true;
        return false;
    }
};