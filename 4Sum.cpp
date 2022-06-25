/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(n==0) return res;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = target - nums[i] - nums[j];
                int start = j+1;
                int end = n-1;
                while(start<end){
                    int sum1 = nums[start]+nums[end];
                    if(sum1 < sum) start++;
                    else if(sum1 > sum) end--;
                    else if(sum1 == sum) {
                        res.push_back({nums[i], nums[j], nums[start], nums[end]});
                        int curr = nums[start];
                        while(start<end && nums[start] == curr) start++;
                        curr = nums[end];
                        while(start<end && nums[end] == curr) end--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};