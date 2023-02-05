

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 
Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();

        if(s_size < p_size)
            return {};

        vector<int> p_freq(26,0);
        vector<int> window(26,0);
        vector<int> ans;

        //first window
        for(int i=0;i<p_size;i++) {
            p_freq[p[i]-'a']++;
            window[s[i]-'a']++;
        }

        if(p_freq == window)
            ans.push_back(0);

        for(int i=p_size;i<s_size;i++) {
            window[s[i-p_size]-'a']--;
            window[s[i]-'a']++;

            if(p_freq == window)
                ans.push_back(i-p_size+1);
        }
        return ans;
    }
};