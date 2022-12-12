/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void find(int inx, string s, vector<vector<string>> &res, vector<string> &ds){
        if(inx == s.size()){
            res.push_back(ds);
            return;
        }
        for(int i=inx; i<s.size(); i++){
            if(isPalimdron(s, inx, i)){
                ds.push_back(s.substr(inx, i-inx+1));
                find(i+1, s, res, ds);
                ds.pop_back();
            }
        }
    }
    
    bool isPalimdron(string s, int start, int end){
        while(start<=end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        find(0, s, res, ds);
        return res;
    }
};