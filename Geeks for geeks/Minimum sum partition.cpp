

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

    ***********************************************************
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  vector<int> subset(int arr[],int sum,int n){
        vector<int> res;
        bool t[n+1][sum+1];
        for(int i=0;i<sum+1;i++){
            t[0][i]=false;
        }
        for(int i=0;i<n+1;i++){
            t[i][0]=true;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                } else {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        for(int i=0;i<=sum/2;i++){
            if(t[n][i] == true){
                res.push_back(i);
            }
        }
        return res;
    }
	int minDifference(int arr[], int n)  { 
	    int range=0;
	    for(int i=0;i<n;i++){
	        range+=arr[i];
	    }
	    vector<int> v;
	    v=subset(arr,range,n);
	    int minimum=INT_MAX;
	    for(int i=0;i<v.size();i++){
	        minimum=min(minimum,range-(2*v[i]));
	    }
	    return minimum;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends