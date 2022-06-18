/* There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. 
HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. 
Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

Sample Input 1:
2
4

10 20 30 10
3
10 50 10

Sample Output 1:
20
0

Explanation Of Sample Input 1:
For the first test case,
The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
So, the total energy lost is 20 which is the minimum. 
Hence, the answer is 20.

For the second test case:
The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
So, the total energy lost is 0 which is the minimum. 
Hence, the answer is 0.


Sample Input 2:
2
8
7 4 4 2 6 6 3 4 
6
4 8 3 10 4 4 

Sample Output 2:
7
2 */


#include<bits/stdc++.h>
using namespace std;

//Recurssion
int f(int n, vector<int> &heights){
    if(n==0) return 0;
    if(n==1) return abs(heights[n] - heights[n-1]);
    int one = abs(heights[n] - heights[n-1]) + f(n-1, heights);
    int two = abs(heights[n] - heights[n-2]) + f(n-2, heights);
    return min(one, two);
}

//Memoization
int f(int n, vector<int> &heights, vector<int> &dp){
    if(n==0) return dp[n] = 0;
    if(n==1) return dp[n] = abs(heights[n] - heights[n-1]);
    if (dp[n] != -1) return dp[n];
    int one = abs(heights[n] - heights[n-1]) + f(n-1, heights, dp);
    int two = abs(heights[n] - heights[n-2]) + f(n-2, heights, dp);
    return dp[n] = min(one, two);
}

//Tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp (n, 0);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for(int i=2; i<n; i++){
        int one = abs(heights[i] - heights[i-1]) + dp[i-1];
        int two = abs(heights[i] - heights[i-2]) + dp[i-2];
        dp[i] = min(one, two);
    }
    return dp[n-1];
}