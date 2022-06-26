/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n<3) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int start = i+1;
            int end = n-1;
            while(start<end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum < 0) start++;
                else if(sum > 0) end--;
                else if(sum == 0) {
                    res.push_back({nums[i], nums[start], nums[end]});
                    int cur = nums[start];
                    while(start<end && nums[start]==cur) start++;
                    cur = nums[end];
                    while(start<end && nums[end]==cur) end--;
                }
            }
        }
        return res;
    }
};