

/* 
    Solution by Nirali Rathod
    
    ***********************************************************
There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person at position k (0-indexed) to finish buying tickets.

Example 1:

Input: tickets = [2,3,2], k = 2
Output: 6
Explanation: 
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.

Example 2:

Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
 

Constraints:

n == tickets.length
1 <= n <= 100
1 <= tickets[i] <= 100
0 <= k < n

    ***********************************************************
*/


/*

Solution 1 - Using queue :

Time Complexity = O(n*m) , where n is the number of people and m is the maximum ticket person want to buy
Space Complexity = O(n)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        for(int i=0;i<tickets.size();i++) {
            q.push({tickets[i],i});
        }
        int time = 0;
        while(!q.empty()) {
            time++;
            int ticket = q.front().first;
            int idx = q.front().second;
            q.pop();

            ticket--;
            if(ticket==0 && idx==k)
                return time;
            if(ticket != 0) {
                q.push({ticket,idx});
            }
        }
        return -1;
    }
};

/*

Solution 2 - Without using queue:

Time Complexity = O(n*m) , where n is the number of people and m is the maximum ticket person want to buy
Space Complexity = O(1)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;

        if(tickets[k] == 1)
            return k+1;

        while(tickets[k] != 0) {
            for(int i=0;i<n;i++) {
                if(tickets[i] != 0) {
                    tickets[i]--;
                    time++;
                }
                if(tickets[k] == 0)
                    return time;
            }
        }
        return time;
    }
};

/*

Solution 3 - Using Single Pass:

Time Complexity = O(n)
Space Complexity = O(1)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        for(int i=0;i<tickets.size();i++) {
            if(i <= k) {
                time += min(tickets[i],tickets[k]);
            } else {
                time += min(tickets[k]-1,tickets[i]);
            }
        }
        return time;
    }
};