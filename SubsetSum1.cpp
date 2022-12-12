/*You are given an array of ‘N’ integers. You have to find the sum of all the subsets in the non-decreasing order of the given array.
For Example
If N=3 and array elements are [1,2].
Following are the subset sums:
0 (by considering empty subset)
1 
2
1+2 = 3
So, subset sum are [0,1,2,3].
Input Format :
The first line of the input contains a single integer, 'T’, denoting the number of test cases.

The first line of each test case will contain a single integer ‘N’, denoting the size of the array.

The second line of each test case contains ‘N’ space-separated integers denoting elements of the array.
Output Format :
For each test case, print the sum of all the subsets in non-decreasing order of the given array.

Print a separate line for each test case.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 15
0 <= nums[i] <= 5000

Time limit: 1 sec
Sample Input 1 :
2
2
1 2
1
0
Sample Output 1 :
0 1 2 3
0 0
Explanation For Sample Output 1:
For the first test case,
Following are the subset sums:
0 (by considering empty subset)
1
2
1+2 = 3
So, subset-sum are [0,1,2,3]

For the second test case,
There are only 2 subsets one is an empty subset and the other contains a single element ‘0’.
Sample Input 2 :
2
3 
1 2 3
2 
4 5
Sample Output 2 :
0 1 2 3 3 4 5 6
0 4 5 9*/

#include<bits/stdc++.h>
using namespace std;

void findSum(int n, vector<int> &nums, vector<int> &res, int sum){
    if(n>=nums.size()){
        res.push_back(sum);
        return;
    }
    findSum(n+1, nums, res, sum+nums[n]);
    findSum(n+1, nums, res, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> res;
    findSum(0, num, res, 0);
    sort(res.begin(), res.end());
    return res;
}