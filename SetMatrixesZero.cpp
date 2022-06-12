/* Given an ‘N’ x ‘M’ integer matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
In particular, your task is to modify it in such a way that if a cell has a value 0 (matrix[i][j] == 0),
then all the cells of the ith row and jth column should be changed to 0.
You must do it in place.

For Example:
If the given grid is this:
[7, 19, 3]
[4, 21, 0]

Then the modified grid will be:
[7, 19, 0]
[0, 0,  0] */

#include<bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	int rows = matrix.size(); int cols = matrix[0].size();
    int isCol = 1;
    
    for(int i=0; i<rows; i++){
        if(matrix[i][0]==0) isCol = 0;
        for(int j=1; j<cols; j++){
            if(matrix[i][j]==0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    for(int i=rows-1; i>=0; i--){
        for(int j=cols-1; j>=1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
        if(isCol==0) matrix[i][0] = 0;
    }
}