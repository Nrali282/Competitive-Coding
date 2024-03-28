

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

 
Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool checkOrder(string s1,string s2,unordered_map<char,int> m) {
        int n = min(s1.length(),s2.length());
        int i=0;
        while(i<n) {
            if(m[s1[i]] > m[s2[i]])
                return false;
            else if(m[s1[i]] < m[s2[i]])
                return true;
            i++;
        }

        if(s1.length() > s2.length())
            return false;

        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m(26);
        for(int i=0;i<26;i++) {
            m[order[i]] = i;
        }
        for(int i=0;i<words.size()-1;i++) {
            if(!checkOrder(words[i],words[i+1],m))
                return false;
        }
        return true;
    }
};