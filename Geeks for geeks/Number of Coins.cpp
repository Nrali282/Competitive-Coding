

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.

Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin

Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
Output: 2 
Explanation: Use one 6 cent coin
and one 5 cent coin

    ***********************************************************
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int t[M+1][V+1];
	    for(int i=0;i<V+1;i++){
	        t[0][i]=INT_MAX-1;
	    }
	    for(int i=1;i<M+1;i++){
	        t[i][0]=0;
	    }
	    for(int i=1;i<M+1;i++){
	        for(int j=1;j<V+1;j++){
	            if(coins[i-1]<=j){
	                t[i][j]=min(t[i][j-coins[i-1]]+1,t[i-1][j]);
	            } else{
	                t[i][j]=t[i-1][j];
	            }
	        }
	    }
	    
	    if(t[M][V]==INT_MAX-1){
	        return -1;
	    }
	    return t[M][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends