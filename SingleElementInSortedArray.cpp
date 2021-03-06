/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]!=nums[(mid+1)%n] && nums[mid]!=nums[(n+mid-1)%n]) return nums[mid];
            else if(nums[mid] == nums[(mid+1)%n]){
                if(mid%2) high = mid-1;
                else low = mid+1;
            }
            else if(nums[mid] == nums[(n+mid-1)%n]){
                if(((mid-1)%n)%2) high =mid-1;
                else low = mid+1;
            }
            
        }
        return -1;
    }
};