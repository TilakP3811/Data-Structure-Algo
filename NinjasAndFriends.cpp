/* Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

Sample Input 1:
2
3
1 2 5 
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
Sample Output 1:
11
210
Explanation Of Sample Input 1:
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points. 
On the second day, Ninja will do running and earn 3 merit points. 
On the third day, Ninja will do fighting and earn 3 merit points. 
The total merit point is 11 which is the maximum. 
Hence, the answer is 11.

For the second test case:
One of the answers can be:
On the first day, Ninja will learn new moves and earn 70 merit points. 
On the second day, Ninja will do fighting and earn 50 merit points. 
On the third day, Ninja will learn new moves and earn 90 merit points. 
The total merit point is 210 which is the maximum. 
Hence, the answer is 210.
Sample Input 2:
2
3
18 11 19
4 13 7
1 8 13
2
10 50 1
5 100 11
Sample Output 2:
45
110 */

//Recurssion
#include<bits/stdc++.h>
using namespace std;

int f(int days, int last, vector<vector<int>> &points){
    if(days==0) {
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i!=last){
                 maxi = max(maxi, points[days][i]);   
            }
        }
        return maxi;
    }
    
    int maxi = 0;
    for(int i=0; i<3; i++){
        if(i!=last){
            int point = points[days][i] + f(days-1, i, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

//Memoization
int f(int days, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(days==0) {
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i!=last){
                 maxi = max(maxi, points[days][i]);   
            }
        }
        return dp[days][last] = maxi;
    }
    if(dp[days][last] != -1) return dp[days][last];
    int maxi = 0;
    for(int i=0; i<3; i++){
        if(i!=last){
            int point = points[days][i] + f(days-1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[days][last] = maxi;
}

//Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int days=1; days<n; days++){
        for(int last=0; last<4; last++){
            for(int i=0; i<3; i++){
                if(i != last){
                     int point = points[days][i] + dp[days-1][i];  
                     dp[days][last] = max(dp[days][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}