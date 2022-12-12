/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void findPermu(int inx, vector<int> &nums, vector<vector<int>> &res){
        if(inx >= nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=inx; i<nums.size(); i++){
            swap(nums[i], nums[inx]);
            findPermu(inx+1, nums, res);
            swap(nums[i], nums[inx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        findPermu(0, nums, res);
        return res;
    }
};