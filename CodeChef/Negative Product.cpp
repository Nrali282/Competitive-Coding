

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

Chef is given three numbers A,B,and C.

He wants to find whether he can select exactly two numbers out of these such that the product of the selected numbers is negative.

Input Format :

The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of three integers A,B, and C, the given numbers.

Output Format :

For each test case, output YES if Chef can select exactly two numbers out of these such that the product of the selected numbers is negative, NO otherwise.

You may print each character in uppercase or lowercase. For example, the strings NO, no, No, and nO, are all considered identical.

Constraints :

1≤T≤1000
−10≤A,B,C≤10

    ***********************************************************
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int a,b,c;
	    cin >> a >> b >> c;
	    bool flag=false;
	    if(a*b < 0)
	        flag=true;
	    if(a*c < 0)
	        flag=true;
	    if(b*c < 0)
	        flag=true;
	    if( flag==true)
	        cout<<"YES"<<"\n";
	    else
	        cout<<"NO"<<"\n";
	}
	return 0;
}
