/* You are given an array of size ‘N’. 
The elements of the array are in the range from 1 to ‘N’.
Ideally, the array should contain elements from 1 to ‘N’. 
But due to some miscalculations, there is a number R in the range [1, N] which appears in the 
array twice and another number M in the range [1, N] which is missing from the array.
Your task is to find the missing number (M) and the repeating number (R).

Sample Input 1:
1 
5
1 3 5 4 4
Sample Output 1:
2 4
Explanation Of Sample Input 1:
As we can clearly see, among all the numbers from 1 to 5, 2 is not present and 4 is occurring twice. Thus, 2 and 4 are missing and repeating numbers respectively. 

Sample Input 2:
2
10
4 5 2 9 8 1 1 7 10 3
7
7 5 3 2 1 6 6 
Sample Output 2:
6 1 
4 6 */

#include<bits/stdc++.h>
using namespace std;

//Swap Sort
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> res;
	for(int i=0; i<n; i++){
        while(i+1 != arr[i]){
            if(arr[arr[i]-1] != arr[i]){
                swap(arr[arr[i]-1], arr[i]);
            }
            else{
                res.first = i+1;
                res.second = arr[i];
                break;
            }
        }
    }
    return res;
}

//Methametical
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> res;
	int sum = n*(n+1)/2;
    int sqSum = n*(n+1)*(2*n+1)/6;
    for(int i=0; i<n; i++){
        sum -= arr[i];
        sqSum -= arr[i]*arr[i];
    }
    int missing = (sum + sum/sqSum)/2;
    int repeating = missing - sum;
    res.first = missing;
    res.second = repeating;
    return res;
}