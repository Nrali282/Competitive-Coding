

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

    ***********************************************************
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapS2T;
        unordered_map<char, char> mapT2S;
        
        for (int i = 0; i < s.size(); ++i) {
            char charS = s[i];
            char charT = t[i];
            
            if (mapS2T.find(charS) != mapS2T.end()) {
                if (mapS2T[charS] != charT) {
                    return false;
                }
            } else { 
                if (mapT2S.find(charT) != mapT2S.end()) {
                    return false;
                }
                
                mapS2T[charS] = charT;
                mapT2S[charT] = charS;
            }
        }
        
        return true;
    }
};