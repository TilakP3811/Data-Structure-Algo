/*Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void find(int n, vector<int> &nums, vector<vector<int>> &res, vector<int> &ds){
        res.push_back(ds);
        for(int i=n; i<nums.size(); i++){
            if(i!=n && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            find(i+1, nums, res, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        find(0, nums, res, ds);
        return res;
    }
};