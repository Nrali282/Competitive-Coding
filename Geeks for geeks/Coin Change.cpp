

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].  
Note: Assume that you have an infinite supply of each type of coin. 

Example 1:

Input:
sum = 4 , 
N = 3
coins[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
Sum = 10 , 
N = 4
coins[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.

    ***********************************************************
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        long long int dp[N+1][sum+1];
        
        for(int i=0;i<sum+1;i++) {
            dp[0][i] = 0;
        }
        
        for(int i=0;i<N+1;i++) {
            dp[i][0] = 1;
        }
        
        for(int i=1;i<N+1;i++) {
            for(int j=1;j<sum+1;j++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends