

/* 
    Solution by Nirali Rathod
    
    ***********************************************************

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(),gas.end(),0);
        int totalCost = accumulate(cost.begin(),cost.end(),0);

        if(totalGas < totalCost)
            return -1;

        int n=gas.size();
        int currGas=0,startIdx=0;
        for(int i=0;i<n;i++){
            currGas+=gas[i]-cost[i];
            if(currGas<0){
                startIdx=i+1;
                currGas=0;
            }
        }
        return startIdx;
    }
};