/* You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

Sample Input 1:
2
2 2
1 1
Sample Output 1:
2
1
Explanation Of Sample Output 1:
In test case 1, we are given a 2 x 2 matrix, to move from matrix[0][0] to matrix[1][1] we have the following possible paths.

Path 1 = (0, 0) -> (0, 1) -> (1, 1)
Path 2 = (0, 0) -> (1, 0) -> (1, 1)

Hence a total of 2 paths are available, so the output is 2.

In test case 2, we are given a 1 x 1 matrix, hence we just have a single cell which is both the starting and ending point. Hence the output is 1.
Sample Input 2:
2
3 2
1 6
Sample Output 2:
3
1
Explanation Of Sample Output 2:
In test case 1, we are given a 3 x 2 matrix, to move from matrix[0][0] to matrix[2][1] we have the following possible paths.

Path 1 = (0, 0) -> (0, 1) -> (1, 1) -> (2, 1)
Path 2 = (0, 0) -> (1, 0) -> (2, 0) -> (2, 1)
Path 3 =  (0, 0) -> (1, 0) -> (1, 1) -> (2, 1)

Hence a total of 3 paths are available, so the output is 3.

In test case 2, we are given a 1 x 6 matrix, hence we just have a single row to traverse and thus total path will be 1. */

#include<bits/stdc++.h>
using namespace std;

//Recurssion
int f(int x, int y){
    if(x==0 && y==0) return 1;
    if(x<0 || y<0) return 0;
    int up = f(x-1, y);
    int left = f(x, y-1);
    return up+left;
}

//Memoization
int f(int x, int y, vector<vector<int>> &dp){
    if(x==0 && y==0) return 1;
    if(x<0 || y<0) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    int up = f(x-1, y, dp);
    int left = f(x, y-1, dp);
    return dp[x][y] = up+left;
}

//Tabulation
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, 0));
    for(int i=0; i<m; i++) dp[i][0] = 1;
    for(int i=0; i<n; i++) dp[0][i] = 1;
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            int up = dp[i-1][j];
            int left = dp[i][j-1];
            dp[i][j] = up + left;
        }
    }
	return dp[m-1][n-1];
}