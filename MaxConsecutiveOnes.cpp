/*Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int i=0, j=0;
        int n = nums.size();
        while(j<n){
            if(nums[j]==1){
                res = max(res, j-i+1);
            }
            else{
                while(j<n && nums[j]==0) j++;
                i = j;
                if(j<n) res = max(res, j-i+1);
            }
            j++;
        }
        return res;
    }
};