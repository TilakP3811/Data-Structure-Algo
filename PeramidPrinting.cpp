#include<bits/stdc++.h>
using namespace std;
/* *
   **
   ***
   ****
   ***** */
void peramid1(int n){
    for(int i=1; i<=n; i++){
        for(int j=n-1; j>=0; j--){
            if(j>=i) cout<<" ";
            else cout<<"* ";
        }
        cout<<endl;
    }
}

//    *
//   ***
//  *****
// *******
void pypart2(int n)
{
    // Number of spaces
    int i, j, k = n;
 
    // Outer loop to handle number of rows
    // n in this case
    for (i = 1; i <= n; i++) {
 
        // Inner loop for columns
        for (j = 1; j <= n; j++) {
 
            // Condition to print star pattern
            if (j >= k)
                cout << "* ";
            else
                cout << "  ";
        }
        k--;
        cout << "\n";
        for(int j=0; j<i; j++) cout<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    peramid1(5);
return 0;
}