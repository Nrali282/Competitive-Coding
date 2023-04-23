

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
Election season has started in Chefland and the election commission wants to know the count of eligible voters.

There are N people in Chefland where the age of the ith person in Ai.
Given that a person needs to be at least X years old to vote, find the number of eligible voters.

Input Format :

The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains two space-separated integers N and X — the number of people in Chefland, and the minimum age required for a person to vote in Chefland.
The next line contains N space-separated integers, where the ith integer denotes the age of the ith person.

Output Format :

For each test case, output on a new line, the number of eligible voters in Chefland.

    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n,x;
	    cin >> n >> x;
	    vector<int> v(n);
	    int c = 0;
	    for(int i=0;i<n;i++) {
	        cin >> v[i];
	        if(v[i] >= x)
	            c++;
	    }
	    cout << c << "\n";
	}
	return 0;
}

