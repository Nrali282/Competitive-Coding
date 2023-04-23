

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
You are given a binary string S of length N.

You have to construct a binary string X, of length N, such that:

Input Format :

The first line of input will contain a single integer T, denoting the number of test cases.
The first line of each test case contains a single integer N, the length of the string S.
The second line of each test case contains a binary string S.

Output Format :

For each test case, output on a new line, the maximum count of 1 in string X.

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
	    string s;
	    cin >> s;
	    string x = "";
	    int c;
	    x += '1';
	   // cout << (x[0] ^ s[0]) << "\n";
	    for(int i=0;i<n-1;i++) {
	        x += (x[i] ^ s[i]);
	        //x += char(t);
	    }
	    cout << x << "\n";
	}
	return 0;
}
