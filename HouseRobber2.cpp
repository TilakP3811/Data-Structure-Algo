/*Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden. All houses along this street are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. 

Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.

Sample Input 1:
3
1
0
3
2 3 2
4
1 3 2 1

Sample Output 1:
0
3
4

Explanation Of Input 1:
(i) Mr. X has only one house to rob, but with no money.

(ii) Mr. X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses (remember, it’s a circular street). So, he’ll rob only house 2 (money = 3) with a maximum value

(iii) Mr. X will get maximum value when he robs house 2 (money = 3) and then robs house 4 (money = 1) i.e. 4 units of money.

Sample Input 2:
3
5
1 5 1 2 6
3
2 3 5
4
1 3 2 0

Sample Output 2:
11
5
3 */

#include<bits/stdc++.h>
using namespace std;

//Recurssion
long long int f(int n, vector<int> &nums){
    if(n==0) return nums[n];
    if(n<0) return 0;
    long long int notTake = f(n-1, nums);
    long long int take = nums[n] + f(n-2, nums);
    return max(notTake, take);
}

long long int houseRobber(vector<int>& nums)
{
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> fh;
    vector<int> lh;
    for(int i=0; i<n; i++){
        if(i!=0) fh.push_back(nums[i]);
        if(i!=n-1) lh.push_back(nums[i]); 
    }
    long long int first = f(fh.size()-1, fh);
    long long int second = f(lh.size()-1, lh);
    return max(first, second);
}

//Memoization
long long int f(int n, vector<int> &nums, vector<long long int> &dp){
    if(n==0) return dp[n] = nums[n];
    if(n<0) return 0;
    if(dp[n] != -1) return dp[n];
    long long int notTake = f(n-1, nums, dp);
    long long int take = nums[n] + f(n-2, nums, dp);
    return dp[n] = max(notTake, take);
}

long long int houseRobber(vector<int>& nums)
{
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> fh;
    vector<int> lh;
    for(int i=0; i<n; i++){
        if(i!=0) fh.push_back(nums[i]);
        if(i!=n-1) lh.push_back(nums[i]); 
    }
    vector<long long int> dp1 (fh.size(), -1);
    vector<long long int> dp2 (lh.size(), -1);
    long long int first = f(fh.size()-1, fh, dp1);
    long long int second = f(lh.size()-1, lh, dp2);
    return max(first, second);
}

//Tabulation
long long int houseRobber(vector<int>& nums)
{
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> fh;
    vector<int> lh;
    for(int i=0; i<n; i++){
        if(i!=0) fh.push_back(nums[i]);
        if(i!=n-1) lh.push_back(nums[i]); 
    }
    vector<long long int> dp1 (fh.size(), 0);
    vector<long long int> dp2 (lh.size(), 0);
    dp1[0] = fh[0];
    dp2[0] = lh[0];
    for(int i=1; i<fh.size(); i++){
        long long int notTake = dp1[i-1];
        long long int take = fh[i];
        if(i>1) take += dp1[i-2];
        dp1[i] = max(notTake, take);
    }
    for(int i=1; i<lh.size(); i++){
        long long int notTake = dp2[i-1];
        long long int take = lh[i];
        if(i>1) take += dp2[i-2];
        dp2[i] = max(notTake, take);
    }
    return max(dp1[fh.size()-1], dp2[lh.size()-1]);
}