/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int i=0, r=n-1;
        while(i<r){
            if(height[i]<=height[r]){
                if(height[i]>=leftMax) leftMax = height[i]; 
                else res += leftMax - height[i];
                i++;
            }
            else{
                if(height[r]>=rightMax) rightMax = height[r];
                else res+= rightMax - height[r];
                r--;
            }
        }
        return res;
    }
};