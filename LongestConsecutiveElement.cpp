/* Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        int res = 1;
        for(int i=0; i<n; i++){
            if(st.find(nums[i]-1) == st.end()){
                int currEle = nums[i];
                int maxi = 1;
                while(st.find(currEle+1) != st.end()){
                    currEle++;
                    maxi++;
                }
                res = max(res, maxi);
            }
        }
        return res;
    }
};