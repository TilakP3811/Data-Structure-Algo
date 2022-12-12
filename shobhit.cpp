#include<bits/stdc++.h>
using namespace std;

double findMed(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMed(nums2,  nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int start = 0;
        int end = n1;
        while(start <= end){
            int cut1 = (start + end)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2){
                    return max(left1, left2);
                }
                else{
                    return (max(left1, left2)+min(right1, right2))/2.0;
                }
            }
            else if(left1 > right2){
                end = cut1-1;
            }
            else{
                start = cut1+1;
            }
        }
        return 0.00;
    }

int main(){
  int n1, n2;
  cin>>n1>>n2;
  vector<int> num1(n1);
  vector<int> num2(n2);
  for(int i=0; i<n1; i++){
    cin>>num1[i];
  }
  for(int i=0; i<n2; i++){
    cin>>num2[i];
  }
  sort(num1.begin(), num1.end());
  sort(num2.begin(), num2.end());
  double res = findMed(num1, num2);
  cout << fixed << setprecision(2) << res;
  return 0;
}