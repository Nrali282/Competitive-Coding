

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

 

Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool dfs(string str,unordered_set<string>& s) {
        for(int i=1;i<str.length();i++) {
            int prefix = s.count(str.substr(0,i));
            int suffix = s.count(str.substr(i));
            if(prefix && suffix)
                return true;
            else if(prefix && dfs(str.substr(i),s))
                return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        vector<string> res;
        for(string i : words){
            if(dfs(i,s))
                res.push_back(i);
        }
        return res;
    }
};