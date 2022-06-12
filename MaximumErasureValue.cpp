/*You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5]. */

// -------Code-------

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        int maxi = 0;
        unordered_map<int, int> mp;
        int i=0; int j=0;
        while(j<size){
            mp[nums[j]]++;
            maxi = maxi + nums[j];
            if(mp.size() == (j-i+1)){
                res = max(maxi, res);
            }
            else{
                while(mp.size() != (j-i+1)){
                    maxi = maxi - nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return res;
    }
};