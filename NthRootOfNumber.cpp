/*You are given two positive integers N and M. You have to find the Nth root of M i.e. M^(1/N).

Sample Input 1:
1
3 27
Sample Output 1:
3.000000
Explanation For Sample Input 1:
3rd Root of 27 is 3.000000, as (3.000000)^3 is equal to 27.
Sample Input 2:
1
4 69
Sample Output 2:
2.882121 */

#include<bits/stdc++.h>
using namespace std;

double multiple(double number, int n){
    double ans = 1.00;
    for(int i=0; i<n; i++) ans = ans * number;
    return ans;
}

double findNthRootOfM(int n, long long m) {
	double low = 1;
    double high = m;
    double epc = 1e-7;
    while((high-low) > epc){
        double mid = (high + low)/2.00;
        if(multiple(mid, n) < (double)m) low = mid;
        else high = mid;
    }
    return low;
}
