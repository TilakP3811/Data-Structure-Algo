/* Ninja loves playing with numbers. So his friend gives him an array on his birthday. The array consists of positive and negative integers. Now Ninja is interested in finding the length of the longest subarray whose sum is zero.

Sample Input 1:
2 
5
1 3 -1 4 -4
4
1 -1 2 -2 

Sample Output 1:
2
4 */

#include<bits/stdc++.h>
using namespace std;
 
 #include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    int res = 0;
    unordered_map<int, int> mp;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == 0) res = max(res, i+1);
        if(mp.find(sum) != mp.end()){
            res = max(res, i - mp[sum]);    
        }
        else{
            mp[sum] = i;
        }
    }
    return res;
}
