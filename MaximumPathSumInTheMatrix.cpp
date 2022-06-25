/*You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.

nput 1 :
2
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1
3 3
10 2 3
3 7 2
8 1 5
Output 1 :
105
25
Explanation Of Input 1 :
In the first test case for the given matrix,

The maximum path sum will be 2->100->1->2, So the sum is 105(2+100+1+2).

In the second test case for the given matrix, the maximum path sum will be 10->7->8, So the sum is 25(10+7+8).
Input 2 :
2
3 3
1 2 3
9 8 7
4 5 6
4 6
10 10 2 -13 20 4
1 -9 -81 30 2 5
0 10 4 -79 2 -10
1 -5 2 20 -11 4
Output 2 :
17
74
Explanation Of Input 2 :
In the first test case for the given matrix, the maximum path sum will be 3->8->6, So the sum is 17(3+8+6).

In the second test case for the given matrix, the maximum path sum will be 20->30->4->20, So the sum is 74(20+30+4+20).*/

#include<bits/stdc++.h>
using namespace std;

//Recurssion
int f(int n, int m, vector<vector<int>> &matrix){
    if(m<0 || m>=matrix[0].size()) return -1e8;
    if(n==0) return matrix[n][m];
    int up = matrix[n][m] + f(n-1, m, matrix);
    int upRight = matrix[n][m] + f(n-1, m+1, matrix);
    int upLeft = matrix[n][m] + f(n-1, m-1, matrix);
    return max(up, max(upRight, upLeft));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int res = -1e8;
    for(int i=0; i<m; i++){
        int maxi = f(n-1, i, matrix);
        res = max(res, maxi);
    }
    return res;
}

//Memoization
int f(int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(m<0 || m>=matrix[0].size()) return -1e8;
    if(n==0) return dp[n][m] = matrix[n][m];
    if(dp[n][m] != -1) return dp[n][m];
    int up = matrix[n][m] + f(n-1, m, matrix, dp);
    int upRight = matrix[n][m] + f(n-1, m+1, matrix, dp);
    int upLeft = matrix[n][m] + f(n-1, m-1, matrix, dp);
    return dp[n][m] = max(up, max(upRight, upLeft));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    int res = -1e8;
    for(int i=0; i<m; i++){
        int maxi = f(n-1, i, matrix, dp);
        res = max(res, maxi);
    }
    return res;
}

//Tebulation
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int i=0; i<m; i++) dp[0][i] = matrix[0][i];
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int up = -1e8, upLeft = -1e8, upRight = -1e8;
            up = matrix[i][j] + dp[i-1][j];
            if(j>0) upLeft = matrix[i][j] + dp[i-1][j-1];
            if(j<m-1) upRight = matrix[i][j] + dp[i-1][j+1];
            dp[i][j] = max(up, max(upLeft, upRight));
        }
    }
    int res = -1e8;
    for(int i=0; i<m; i++){
        res = max(res, dp[n-1][i]);
    }
    return res;
}