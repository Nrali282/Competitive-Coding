

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int i=0;
        while(i < s.length()) {
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='[')
                stack.push(ch);
            else {
                if(stack.empty())
                    return false;
                    
                if((stack.top()=='(' && ch==')') 
                    || (stack.top()=='{' && ch=='}') 
                    || (stack.top()=='[' && ch==']')) {
                        stack.pop();
                } else {
                    return false;
                }
            }
            i++;
        }
        if(!stack.empty())
            return false;

        return true;
    }
};