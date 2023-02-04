

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 
Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26,0);
        for(char c : s1) 
            v[c - 'a']++;
        
        int j = 0, i = 0, total_chars = s1.size();

        while(j < s2.size()) {
            if(v[s2[j++] - 'a']-- > 0) {
                total_chars--;
            }
            if(total_chars == 0)
                return true;
            
            //shifting of window
            if(j - i == s1.size() && v[s2[i++] - 'a']++ >= 0) {
                total_chars++;
            }
        }
        return false;
    }
};