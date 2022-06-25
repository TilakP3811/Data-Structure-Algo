/*Given a string input of length n, find the length of the longest substring without repeating characters i.e return a substring that does not have any repeating characters.
Substring is the continuous sub-part of the string formed by removing zero or more characters from both ends.

Sample Input 1:
 abcabcbb 

Sample Output1:
 3

Explanation For Sample Input 1:
Substring "abc" has no repeating character with the length of 3.

Sample Input 2:
 aaaa

Sample Output 2:
1 */

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int n = input.size();
    int res = 1;
    unordered_map<char, int> mp;
    int i=0, j=0;
    while(j<n){
        mp[input[j]]++;
        if(mp.size() == (j-i+1)){
            res = max(res, (j-i+1));
        }
        while(mp.size() != (j-i+1)){
            mp[input[i]]--;
            if(mp[input[i]]==0) mp.erase(input[i]);
            i++;
        }
        j++;
    }
    return res;
}