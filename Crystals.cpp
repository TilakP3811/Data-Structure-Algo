/*Ninja wants to buy 'N' items on his favorite E-Commerce 'CRYSTAL'. Discounts on 'CRYSTAL' will last for a week, However, not all sellers on the platform are sincere and some will increase their price after the week.
Ninja knows someone on the inside and hence knows the current price of the 'N' items given as an array 'X' and also their price after a week given as array 'Y'.
He will buy at least 'K' items now and buy the remaining 'N-K' items after the week is over to save as much as possible. Determine the minimum amount he will spend.Sample Input 1 :
2
2 1
8 9
5 7
2 2
5 5
1 1
Sample Output 1 :
14
10
Explanation Of Sample Input 1 :
For test case 1:
Ninja has to buy at least 1 item before the week is over. He will buy the item indexed 1 (assume 0-based indexing) for 'X[1]' = 9 and buy the second item after the week for 'Y[0]' = 5. In this way, he will spend a total of 9+5 = 14 which is the minimum possible.

For test case 2:
Since 'N' = 2 and 'K' = 2, Ninja will have to buy all the items before the week is over. Hence total cost is 'X[0] + X[1]' = 5+5 = 10.
Sample Input 2 :
2
6 3
9 9 9 2 2 2
6 6 6 1 1 1
5 2
2 4 4 4 4
3 1 1 1 1
Sample Output 2 :
24
9 */

#include<bits/stdc++.h>
using namespace std;

int SavingMoney(int n, int k, vector<int> &x, vector<int> &y) {
	vector<pair<int, int>> diff;
    int neg = 0;
    for(int i=0; i<n; i++){
        diff.push_back({x[i]-y[i], i});
        if(x[i]-y[i] < 0) neg++;
    }
    int res = 0;
    sort(diff.begin(), diff.end());
    if(neg<k){
        for(int i=0; i<n; i++){
            if(i<k) res += x[diff[i].second];
            else res += y[diff[i].second];
        }
    }
    else{
        for(int i=0; i<n; i++){
             if(diff[i].first<0) res += x[diff[i].second];
            else res += y[diff[i].second];   
        }
    }
    return res;
}