

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.

    ***********************************************************
*/


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        int dp[n+1][sum+1];
        
        for(int i=0;i<n+1;i++) {
            dp[i][0] = 1;
        }
        
        for(int i=1;i<sum+1;i++) {
            dp[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<sum+1;j++) {
                if(arr[i-1] <= j) {
                    int s1 = dp[i-1][j-arr[i-1]];
                    int s2 = dp[i-1][j];
                    dp[i][j] = s1 || s2;
                } else {
                    dp[i][j] = dp[i-1][j];
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
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends