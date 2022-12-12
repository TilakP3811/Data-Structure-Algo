#include<bits/stdc++.h>
using namespace std;

int findMinSweetness(vector<int> nums, int k){
  int size = nums.size();
  int i=0, j=0;
  unordered_map<int, int>mp;
  deque<int>q;
  
  while(j<size){
    while(!q.empty() && q.back() < nums[j]){
        q.pop_back();
    }
    q.push_back(nums[j]);
    if((j-i+1) < k){
        j++;
    }
    else if((j-i+1) == k){
        mp[q.front()]++;
        if(nums[i] == q.front()){
            q.pop_front();
        }
        i++; j++;
    }
  }
  while(i<size){
    mp[q.front()]++;
    i++;
  }
  int res = 0;
  for(auto it : mp){
    res = max(res, it.second);
  }
  return res;
}

int main(){
  int n;
  int k;
  cin>>n>>k;
  vector<int> nums (n);
  for(int i=0; i<n; i++){
    cin>>nums[i];
  }
  int res = findMinSweetness(nums, k+1);
  cout<<res;
  return 0;
}