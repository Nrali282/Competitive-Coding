

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 

Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length())
            return false;

        if(s == goal) {
            vector<int> frequency(26,0);
            for(auto ch:s) {
                frequency[ch - 'a'] += 1;
                if(frequency[ch - 'a'] == 2) {
                    return true;
                }
            }
            return false;
        }

        int firstIdx = -1;
        int secondIdx = -1;

        for(int i=0;i<s.size();i++) {
            if(s[i] != goal[i]) {
                if(firstIdx == -1) {
                    firstIdx = i;
                } else if(secondIdx == -1) {
                    secondIdx = i;
                } else {
                    return false;
                }
            }
        }

        if(secondIdx == -1) 
            return false;

        return s[firstIdx] == goal[secondIdx] && s[secondIdx] == goal[firstIdx];
    }
};