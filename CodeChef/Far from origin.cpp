

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Alex, Bob, and, Chef are standing on the coordinate plane. Chef is standing at the origin (coordinates (0,0)) while the location of Alex and Bob are 
(X1,Y1) and (X2,Y2) respectively.

Amongst Alex and Bob, find out who is at a farther distance from Chef or determine if both are at the same distance from Chef.

Input Format :

The first line of input will contain a single integer T, denoting the number of test cases.
The first and only line of each test case contains four space-separated integers 
X1,Y1,X2, and Y2 — the coordinates of Alex and Bob.
  
Output Format :

For each test case, output on a new line:

ALEX, if Alex is at a farther distance from Chef.
BOB, if Bob is at a farther distance from Chef.
EQUAL, if both are standing at the same distance from Chef.

You may print each character in uppercase or lowercase. For example, Bob, BOB, bob, and bOB, are all considered identical.

    ***********************************************************
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>> t;
	while(t--) {
	    int x1,y1,x2,y2;
	    cin >> x1 >> y1 >> x2 >>y2;
	    float a = sqrt((x1*x1)+(y1*y1));
	    float b = sqrt((x2*x2)+(y2*y2));
	    if(a>b)
	        cout<<"ALEX"<<"\n";
	    else if(a<b)
	        cout<<"BOB"<<"\n";
	    else
	        cout<<"EQUAL"<<"\n";
	}
	return 0;
}
