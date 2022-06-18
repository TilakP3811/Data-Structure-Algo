/* You are given an array/list of ‘N’ integers. 
You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Sample Input 1:
2
3
1 2 4
4
2 1 4 9

Sample Output 1:
5
11

Explanation To Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

Sample Input 2:
2
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9

Sample Output 2:
8
24

Explanation To Sample Output 2:
In test case 1, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]' and 'ARR[4]', i.e. 8, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

In test case 2, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]', 'ARR[4]', 'ARR[6]' and 'ARR[8]', i.e. 24 so, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list. */

#include<bits/stdc++.h>
using namespace std;

//Recurssion
int f(int n, vector<int> &nums){
    if(n==0) return nums[n];
    if(n<0) return 0;
    int take = f(n-1, nums);
    int notTake = nums[n] + f(n-2, nums);
    return max(take, notTake);
}

//Memoization
int f(int n, vector<int> &nums, vector<int> &dp){
    if(n==0) return dp[n] = nums[n];
    if(n<0) return 0;
    if(dp[n] != -1) return dp[n];
    int take = f(n-1, nums, dp);
    int notTake = nums[n] + f(n-2, nums, dp);
    return dp[n] = max(take, notTake);
}

//Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp (nums.size(), 0);
    dp[0] = nums[0];
    for(int i=1; i<n; i++){
        int take = dp[i-1];
        int notTake = nums[i];
        if(i>1) notTake += dp[i-2];
        dp[i] = max(take, notTake);
    }
    return dp[n-1];
}