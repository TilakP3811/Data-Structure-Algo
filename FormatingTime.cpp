#include<bits/stdc++.h>
using namespace std;

string format(string time){
    int n = time.size();
    string hh = time.substr(0, 2);
    string res = time.substr(2, n);
    int HH = stoi(hh);
    if(HH < 12){
        res = res + " AM";
        if(HH==0) HH=12;
    }
    else res = res + " PM";
    if(HH > 12) HH -= 12;
    hh = to_string(HH);
    return hh+res;
}

int main(){
    string time;
    cin>>time;
    string res = format(time);
    cout<<res<<endl;
return 0;
}