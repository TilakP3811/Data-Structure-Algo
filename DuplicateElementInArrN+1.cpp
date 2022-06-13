/* You are given an array of integers 'ARR' containing N elements. 
Each integer is in the range [1, N-1], with exactly one element repeated in the array.
Your task is to find the duplicate element.

Sample Input 1:
1
3
1 1 2
Sample Output 1:
1
Explanation of Sample Input 1:
1 is repeated in the array, hence function returns 1.

Sample Input 2:
3
5
1 3 4 2 2
5
3 1 3 4 2
3
1 1 1
Sample Output 2:
2
3
1 */

#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	int slow = arr[0];
    int fast = arr[0];
    
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow!=fast);
    
    fast = arr[0];
    while(fast != slow){
        slow = arr[slow];
        fast = arr[fast];
    }
    return fast;
}