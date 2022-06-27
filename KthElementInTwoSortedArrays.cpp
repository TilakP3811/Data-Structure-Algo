/*Ninja wants to serve food to needy people. So, he bought Ladoos from a sweet shop and placed them on plates. There can be any number of Ladoos present in a plate.
Plates containing Ladoos are placed in two rows. Each row is sorted in increasing order by the number of Ladoos in a plate.
For Example :
‘ROW1’ :  [2, 5, 8, 17] and  ‘ROW2’ :  [1, 4, 8, 13, 20]
Now people come one by one in a line to take plates of Ladoos from Ninja. Ninja picks the two plates in front, one from each row and gives that plate to people in which the number of ladoos is the smallest (if both plates contain equal numbers of ladoos then he serves any plate from the two plates) and places the other plate back to its position.

Sample Input 1 :
2
5 4 3
3 11 23 45 52
4 12 14 18
1 1 2
1
2
Sample Output 1 :
11
 2
Explanation For Sample Output 1 :
For sample test case 1: 
1’st person will get 3 ladoos i.e a minimum of 3 and 4. Now  ‘ROW1’ :  [11, 23, 45, 52] and  ‘ROW2’ :  [4, 12, 14, 18].
2’nd person will get 4 ladoos i.e minimum of 11 and 4. Now  ‘ROW1’ :  [11, 23, 45, 52] and  ‘ROW2’ :  [12, 14, 18].
3’rd person will get 11 ladoos i.e minimum of 11 and 12. 

 For sample test case 2: 
1’st person will get 1 ladoos i.e a minimum of 1 and 2. Now  ‘ROW1’ :  [ ] and  ‘ROW2’ :  [2].
2’st person will get 2 ladoos because we have only one element left in ROW2 . Now  ‘ROW1’ :  [] and  ‘ROW2’ :  [].
Sample Input 2 :
2
5 3
1 3 6 7 10
3 5 5 7
3 3 2
10 20 20
1 2 3 
Sample Output 2 :
3 
2*/

#include<bits/stdc++.h>
using namespace std;

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) {
    if(n<m) return ninjaAndLadoos(row2, row1, m, n, k);
    int start = max(0, k-m);
    int end = min(k, n);
    while(start<=end){
        int cut1 = (start+end)/2;
        int cut2 = k - cut1;
        
        int left1 = cut1==0 ? INT_MIN : row1[cut1-1];
        int left2 = cut2==0 ? INT_MIN : row2[cut2-1];
        
        int right1 = cut1==n ? INT_MAX : row1[cut1];
        int right2 = cut2==m ? INT_MAX : row2[cut2];
        
        if(left1<=right2 && left2<=right1) return max(left1, left2);
        else if(left1 > right2) end = cut1-1;
        else start = cut1 + 1;
    }
    return 0;
}