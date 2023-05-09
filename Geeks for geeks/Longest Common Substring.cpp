

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given two strings. The task is to find the length of the longest common substring.

Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.

Example 2:

Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

    ***********************************************************
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int dp[n+1][m+1];
        
        for(int i=0;i<n+1;i++) {
            dp[i][0] = 0;
        }
        
        for(int i=0;i<m+1;i++) {
            dp[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<m+1;j++) {
                if(S1[i-1] == S2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n+1;i++) {
            for(int j=0;j<m+1;j++) {
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends