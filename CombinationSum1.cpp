/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void findCombination(int n, int target, vector<int> &candidates, vector<vector<int>> &res, vector<int> &ds){
        if(n>=candidates.size()){
            if(target==0){
                res.push_back(ds);
            }
            return;
        }
        if(candidates[n] <= target){
            ds.push_back(candidates[n]);
            findCombination(n, target-candidates[n], candidates, res, ds);
            ds.pop_back();
        }
        findCombination(n+1, target, candidates, res, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        findCombination(0, target, candidates, res, ds);
        return res;
    }
};