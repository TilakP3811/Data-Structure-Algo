/* Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10 */

#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>& triangle, int rows){
        if(i >= rows-1) return triangle[i][j];
        int left = triangle[i][j] + f(i+1, j, triangle, rows);
        int right = triangle[i][j] + f(i+1, j+1, triangle, rows);
        return min(left, right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        return f(0, 0, triangle, rows);
    }
};

//Memoiation
class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>& triangle, int rows, vector<vector<int>> &dp){
        if(i >= rows-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int left = triangle[i][j] + f(i+1, j, triangle, rows, dp);
        int right = triangle[i][j] + f(i+1, j+1, triangle, rows, dp);   
        return dp[i][j] = min(left, right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int cols = triangle[rows-1].size();
        vector<vector<int>> dp (rows, vector<int> (cols, -1));
        return f(0, 0, triangle, rows, dp);
    }
};

//Bottom up
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> dp(rows, vector<int> (rows, 0));
        for(int i=rows-1; i>=0; i--){
            dp[rows-1][i] = triangle[rows-1][i];
        }
        for(int i=rows-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                dp[i][j] = min((triangle[i][j]+dp[i+1][j]), (triangle[i][j]+dp[i+1][j+1]));
            }
        }
        return dp[0][0];
    }
};