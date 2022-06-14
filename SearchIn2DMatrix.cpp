/* Problem Statement
You have been given a 2-D array 'MAT' of size M x N where 'M' and 'N' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order.
Moreover, the first element of a row is greater than the last element of the previous row (if exists).
You are given an integer 'TARGET' and your task is to find if it exists in the given 'MAT' or not.

Sample Input 1 :
1
3 4 8
1 2 3 4
5 6 7 8
9 10 11 12

Sample Output 1 :
TRUE

Explanation For Sample Input 1 :
The 'TARGET' = 8 exists in the 'MAT' at index (1, 3).

Sample Input 2 :
2
3 3 78
1 2 4 
6 7 8
9 10 34
2 2 8
1 1
4 8

Sample Output 2 :
FALSE
TRUE

Explanation For Sample Input 2 :
The 'TARGET' = 78 do not exists in the 'MAT'.
The 'TARGET' = 8 exists in the 'MAT' at index (1, 1). */

#include<bits/stdc++.h>
using namespace std;

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int low = 0;
    int high = (m*n)-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(mat[mid/n][mid%n] < target){
            low = mid+1;
        }
        else if(mat[mid/n][mid%n] > target){
            high = mid-1;
        }
        else{
            return true;
        }
    }
    return false;
}