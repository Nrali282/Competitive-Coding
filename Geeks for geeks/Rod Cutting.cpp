

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
Note: Consider 1-based indexing.

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.

Example 2:

Input:
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output: 24
Explanation: 
The maximum obtainable value is 
24 by cutting the rod into 8 pieces 
of length 1, i.e, 8*3=24.

    ***********************************************************
*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        int length[n];
        for(int i=0;i<n;i++) {
            length[i] = i+1;
        }
        
        int dp[n+1][n+1];
        
        for(int i=0;i<n+1;i++) {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<n+1;j++) {
                if(length[i-1] <= j) {
                    dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j - length[i-1]]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends