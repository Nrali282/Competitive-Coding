

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Chef has two arrays A and B of the same size N.

In one operation, Chef can:

Choose two integers i and j(1≤i,j≤N) and swap the elements Ai and Bj.

Chef came up with a task to find the minimum possible value of (Amax − Amin) after performing the swap operation any (possibly zero) number of times.

Since Chef is busy, can you help him solve this task?

Note that Amax and Amin denote the maximum and minimum elements of the array A respectively.

Input Format :

The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
	The first line of each test case contains one integer N — the number of elements in each array.
	The second line consists of N space-separated integers A1,A2,…,AN denoting the elements of the array A.
	The third line consists of N space-separated integers B1,B2,…,BN denoting the elements of the array B.
	
Output Format :

For each test case, output on a new line, the minimum possible value of (A 
max − Amin) in the array A after doing swap operation any number of times.

    ***********************************************************
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<long long int> v(2*n);
	    for(int i=0;i<2*n;i++){
	        cin >> v[i];
	    }
	    sort(v.begin(),v.end());
	    long long int res = 1e9;
	    for(int i=0;i<=n;i++) {
	        res = min( res, v[n+i-1]-v[i]);
	    }
	    cout << res <<"\n";
	}
	return 0;
}