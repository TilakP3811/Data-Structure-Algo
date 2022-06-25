/*Given an array of integers ‘ARR’ and an integer ‘X’, you are supposed to find the number of subarrays of 'ARR' which have bitwise XOR of the elements equal to 'X'.

Sample Input 1 :
2
5 8
5 3 8 3 10
3 7
5 2 9

Sample Output 1 :
2
1*/

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int xr = 0;
    int res = 0;
    for(int i=0; i<n; i++){
        xr = xr^arr[i];
        if(xr==x) res++;
        if(mp.find(xr^x) != mp.end()){
            res += mp[xr^x];
        }
        mp[xr]++;
    }
    return res;
}