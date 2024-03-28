

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

Example 1:

Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}

Example 2:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
             {2, 3, 5}

    ***********************************************************
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        long long dp[n+1][sum+1];
	    long long mode=1e9+7;
        
        for(int i=0;i<n+1;i++) {
            dp[i][0] = 1;
        }
        
        for(int i=1;i<sum+1;i++) {
            dp[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++) {
            for(int j=0;j<sum+1;j++) {
                if(arr[i-1] <= j) {
                    int s1 = dp[i-1][j-arr[i-1]] % mode;
                    int s2 = dp[i-1][j] % mode;
                    dp[i][j] = (s1 + s2) % mode;
                } else {
                    dp[i][j] = dp[i-1][j] % mode;
                }
            }
        }
        return dp[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends