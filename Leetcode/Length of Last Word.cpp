

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

    ***********************************************************
*/

//solution 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream iss(s);
        string str;

        while( iss >> str) {
        }

        return str.size();
    }
};

//solution 2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count =0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' ' && count!=0){
                return count;
            }
            if(s[i]!=' '){
                count++;
            }
        }
        return count;
    }
};