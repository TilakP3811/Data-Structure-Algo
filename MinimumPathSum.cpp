 /* Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.

Sample Input 1:
2
2 3
5 9 6
11 5 2
1 1
5
Sample Output 1:
21
5
Explanation For Sample Output 1:
In test case 1, Consider a grid of 2*3:

For this the grid the path with minimum value is (0,0) -> (0,1) -> (1,1) -> (1,2). And the sum along this path is 5 + 9 +5 + 2 = 21. So the ans is 21.

In test case 2, The given grid is:

For this the grid the path with minimum value is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2).The sum along this path is 1 + 2 + 3 + 4 + 9 = 19.
Sample Input 2:
2
2 2
5 6
1 2
3 3
1 2 3
4 5 4
7 5 9
Sample Output 2:
8
19 */

#include<bits/stdc++.h>
using namespace std;

//Recurssion
int f(int n, int m, vector<vector<int>> &grid){
    if(n==0 && m==0) return grid[n][m];
    if(n<0 || m<0) return 1e8;
    int up = grid[n][m] + f(n-1, m, grid);
    int left = grid[n][m] + f(n, m-1, grid);
    return  min(up, left);
}

//Memoization
int f(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(n==0 && m==0) return dp[n][m] = grid[n][m];
    if(n<0 || m<0) return 1e8;
    if(dp[n][m] != -1) return dp[n][m];
    int up = grid[n][m] + f(n-1, m, grid, dp);
    int left = grid[n][m] + f(n, m-1, grid, dp);
    return dp[n][m] = min(up, left);
}

//Tabulation
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size(); 
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                int up = 1e8, left = 1e8;
                if(i>0) up = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n-1][m-1];
}