/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,  nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int start = 0;
        int end = n1;
        while(start <= end){
            int cut1 = (start + end)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2){
                    return max(left1, left2);
                }
                else{
                    return (max(left1, left2)+min(right1, right2))/2.0;
                }
            }
            else if(left1 > right2){
                end = cut1-1;
            }
            else{
                start = cut1+1;
            }
        }
        return 0.0;
    }
};