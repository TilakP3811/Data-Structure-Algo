/* You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps. 
You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.

Sample Input 1 :
2
2
3

Sample Output 1 :
2
3

Explanation Of Sample Input 1 :
In the first test case, there are only two ways to climb the stairs, i.e. {1,1} and {2}.
In the second test case, there are three ways to climb the stairs i.e. {1,1,1} , {1,2} and {2,1}.

Sample Input 2 :
2
4
5

Sample Output 2 :
5
8

Explanation Of Sample Input 2 :
In the first test case, there are five ways to climb the stairs i.e. {1,1,1,1} , {1,1,2} , {2,1,1} , {1,2,1} , {2,2}.
In the second test case, there are eight ways to climb the stairs i.e. {1,1,1,1,1} , {1,1,1,2} , {1,1,2,1}, {1,2,1,1}, {2,1,1},{2,2,1},{2,1,2} and {2,2,1}. */

#include<bits/stdc++.h>
using namespace std;

//Recurssion

int f(long long n){
    if(n == 0) return 1;
    if(n == 1) return 0;
    int left = f(n-1);
    int right = f(n-2);
    return left+right;
}

//Memoization

int f(long long n, vector<long long> &dp){
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    int left = f(n-1, dp);
    int right = f(n-2, dp);
    return dp[n] = left + right;
}