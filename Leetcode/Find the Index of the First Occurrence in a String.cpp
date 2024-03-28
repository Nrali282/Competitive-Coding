

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        if(needle.length()>haystack.length()){
            return -1;
        }
        size_t found=haystack.find(needle);
        if(found != string::npos){
            return found;
        }
        return -1;
    }
};