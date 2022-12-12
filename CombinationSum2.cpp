/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void findCom(int n, int target, vector<int> &candidates, vector<vector<int>> &res, vector<int> &ds){
        if(target==0){
            res.push_back(ds);
            return;
        }
        for(int i=n; i<candidates.size(); i++){
            if(i>n && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            findCom(i+1, target-candidates[i], candidates, res, ds);
            ds.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        findCom(0, target, candidates, res, ds);
        return res;
    }
};