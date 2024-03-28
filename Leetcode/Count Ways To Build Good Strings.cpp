

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.

Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".

    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int mod = 1e9+7;

        for(int i=1;i<=high;i++) {
            if(i >= zero) {
                dp[i] += dp[i - zero];
            }
            if(i >= one) {
                dp[i] += dp[i - one];
            }
            dp[i] %= mod;
        }

        int ans = 0;
        for(int i = low; i <= high; i++) {
            ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
};