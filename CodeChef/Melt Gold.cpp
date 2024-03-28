

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Chef has an ore with melting point of X degrees.
Chef’s kiln has a initial temperature of Y degrees. The temperature of the kiln increases by i degrees after the ith minute.

Find the minimum time in minutes after which the ore starts melting.

Note:

We are only concerned about the temperature at the end of each minute and not during a minute.
The ore starts melting if the temperature of the kiln becomes greater than or equal to the melting point.

Input Format :

The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two space-separated integers X and Y — the melting point of the ore and the initial temperature of kiln.

Output Format :

For each test case, output on a new line, the minimum time in minutes after which the ore starts melting.

    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int x,y;
	    cin >> x >> y;
	    int i = 1, res = 0;
	    while(x > y) {
	        y += i;
	        i++;
	        res++;
	    }
	    cout << res << "\n";
	}
	return 0;
}

