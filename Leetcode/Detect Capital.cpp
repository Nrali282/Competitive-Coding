

/* 
    Solution by Nirali Rathod
    
    ***********************************************************


We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        if(word.size()==1)
            return true;
        
        for(int i=0;i<word.size();i++){
            if(isupper(word[i]))
                count++;
        }

        if(count==1 && isupper(word[0])){
            return true;
        }
        if(count == 0 || count==word.size())
            return true;
        else
            return false;
    }
};