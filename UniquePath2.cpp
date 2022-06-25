/* Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.

Sample Input 1 :
2    
2 2
0 0
0 0
3 3
0 0 0 
0 -1 0 
0 0 0
Sample Output 1 :
2
2
Explanation For Sample Output 1 :
For the first test case, there are two possible paths to reach (2, 2) from (1, 1) : 
    (1, 1) -> (1, 2) -> (2, 2)
    (1, 1) -> (2, 1) -> (2, 2)

For the second test case, there are two ways to reach the bottom left corner - 
(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)
Sample Input 2 :
1
2 2
0 -1
-1  0
Sample Output 2 :
0 */

#include<bits/stdc++.h>
using namespace std;

//Recurssion
int f(int n, int m, vector<vector<int>> &mat){
    if(n==0 && m==0) return 1;
    if(n<0 || m<0) return 0;
    if(mat[n][m]==-1) return 0;
    int up = f(n-1, m, mat);
    int left = f(n, m-1, mat);
    return up + left;
}

//Memoization
int f(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(n==0 && m==0) return 1;
    if(n<0 || m<0) return 0;
    if(mat[n][m]==-1) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    int up = f(n-1, m, mat, dp);
    int left = f(n, m-1, mat, dp);
    return dp[n][m] = up + left;
}

//Tabulation
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == -1) dp[i][j] = 0;
            else if(i==0 && j==0) dp[i][j] = 1;
            else{
                int up = 0, left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = (up+left);
            }
        }
    }
    return dp[n-1][m-1];
}