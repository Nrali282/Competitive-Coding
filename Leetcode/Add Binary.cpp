

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        string ans="";

        while(i>=0 || j>=0 || carry) {
            if(i>=0) {
                carry += a[i]-'0';
                i--;
            }

            if(j>=0) {
                carry += b[j]-'0';
                j--;
            }

            ans = (to_string)(carry%2) + ans;
            carry = carry/2;
        }
        return ans;
    }
};