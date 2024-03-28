

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Chef has a binary strings S of length N, and an integer K.
Hitesh wants to maximize the decimal representation of S using K operations of the following type:

Type 1: Insert 0 at any position in the string.
Type 2: Change any 0 to 1.

Help Hitesh find the modified string with maximum possible decimal representation after performing at most K operations.

Input Format :

First line will contain T, number of test cases. Then the test cases follow.
The first line of each test case contains two integers N and K.
The second line contains the string S.

Output Format :
For each test case, output on a new line, the modified string with maximum possible decimal representation after performing at most K operations.

    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    string s;
	    cin >> s;
	    if(s[0] != '1') {
	        s[0] = '1';
	        k--;
	    }
	    while(k--) {
	        s += '0';
	    }
	    cout << s << "\n";
	}
	return 0;
}
