/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(st.empty()){
                st.push(s[i]);
            }
            else if(!st.empty()){
                if(s[i]==')'){
                    if(st.top()=='(') st.pop();
                    else st.push(s[i]);
                }
                else if(s[i]=='}'){
                    if(st.top()=='{') st.pop();
                    else st.push(s[i]);
                }
                else if(s[i]==']'){
                    if(st.top()=='[') st.pop();
                    else st.push(s[i]);
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};