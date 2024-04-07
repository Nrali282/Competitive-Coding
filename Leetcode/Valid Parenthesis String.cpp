

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "(*)"
Output: true

Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

    ***********************************************************
*/


/*

Solution 1 - Stack + visted array :

Time Complexity = O(n)
Space Complexity = O(n)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openBrackets;
        stack<int> asterisks;

        for(int i=0;i<s.length();i++) {
            char ch = s[i];

            if(ch == '(') {
                openBrackets.push(i);
            } else if(ch == '*') {
                asterisks.push(i);
            } else {
                if(!openBrackets.empty()) {
                    openBrackets.pop();
                } else if(!asterisks.empty()) {
                    asterisks.pop();
                } else {
                    return false;
                }
            }
        }

        while(!openBrackets.empty() && !asterisks.empty()) {
            if(openBrackets.top() > asterisks.top()) {
                return false;
            }
            openBrackets.pop();
            asterisks.pop();
        }

        return openBrackets.empty();
    }
};

/*

Solution 1 - Stack:

Time Complexity = O(n)
Space Complexity = O(1)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0;
        int closeCount = 0;
        int length = s.length()-1;

        for (int i = 0; i <= length; i++) {
            if (s[i] == '(' || s[i] == '*') {
                openCount++;
            } else {
                openCount--;
            }
            
            if (s[length - i] == ')' || s[length - i] == '*') {
                closeCount++;
            } else {
                closeCount--;
            }

            if (openCount < 0 || closeCount < 0) {
                return false;
            }
        }
        return true;
    }
};