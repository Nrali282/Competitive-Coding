

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

Constraints:

1 <= s.length <= 20
s consists of digits only.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool check(string s) {
        int n = s.size();
        if(n==1)
            return true;

        if(n>3 || s[0]=='0')
            return false;

        int val = stoi(s);
        if(val > 255)
            return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> res;

        if(n>12)
            return res;
        
        for(int i=1;i<=3;i++) {
            for(int j=1;j<=3;j++) {
                for(int k=1;k<=3;k++) {
                    if(i+j+k<n && i+j+k+3>=n) {
                        string a = s.substr(0,i);
                        string b = s.substr(i,j);
                        string c = s.substr(i+j,k);
                        string d = s.substr(i+j+k);

                        if(check(a)&&check(b)&&check(c)&&check(d))
                            res.push_back(a+"."+b+"."+c+"."+d);
                    }
                }
            }
        }
        return res;
    }
};