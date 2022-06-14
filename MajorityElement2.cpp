/* You are given an array/list 'ARR' of integers of length ‘N’. 
You are supposed to find all the elements that occur strictly more than floor(N/3) times in the given array/list.

Sample Input 1 :
2
7
3 2 2 1 5 2 3
5
7 4 4 9 7

Sample Output 1:
2
4 7

Explanation Of Sample Input 1:
In the first test case, floor(N/3) = floor(7/3) is equal to 2, and 2 occurs 3 times which is strictly more than N/3. No other element occurs more than 2 times.

In the second test case, floor(N/3) = floor(5/3) is equal to 1, and 4 and 7 both occur 2 times. No other element occurs more than once.

Sample Input 2:
2
6
1 2 4 4 3 4
4
6 6 6 7

Sample Output 2:
4
6

Explanation Of Sample Input 2:
In the first test case, floor(N/3) = floor(6/3) is equal to 2, and 4 occurs 3 times which is strictly more than N/3. No other element occurs more than 2 times.

In the second test case, floor(N/3) = floor(4/3) is equal to 1, and 6 occurs 3 times. No other element occurs more than once. */

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int ele1 = -1;
    int ele2 = -1;
    int count1 = 0;
    int count2 = 0;
    for(int i=0; i<n; i++){
        if(ele1 == arr[i]) count1++;
        else if (ele2 == arr[i]) count2++;
        else if (count1 == 0) {
            ele1 = arr[i];
            count1++;
        }
        else if (count2 == 0) {
            ele2 = arr[i];
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }
    
    int el1 = 0, el2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele1) el1++;
        else if (arr[i] == ele2) el2++;
    }
    
    vector<int> res;
    if(el1 > n/3) res.push_back(ele1);
    if(el2 > n/3) res.push_back(ele2);
    return res;
}