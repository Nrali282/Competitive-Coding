

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 
Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 

Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.

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
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        vector<int> vis(n,1);
        stack<int> st;

        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if(!st.empty()) {
                    st.pop();
                } else {
                    vis[i] = 0;
                }
            }
        }

        while(!st.empty()) {
            vis[st.top()] = 0;
            st.pop();
        }

        string ans = "";
        for(int i=0;i<n;i++) {
            if(vis[i] == 1) {
                ans += s[i];
            }
        }
        return ans;
    }
};

/*

Solution 1 - Stack:

Time Complexity = O(n)
Space Complexity = O(n)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;

        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if(!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '#';
                }
            }
        }

        while(!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }

        string ans = "";
        for(int i=0;i<n;i++) {
            if(s[i] != '#') {
                ans += s[i];
            }
        }
        return ans;
    }
};