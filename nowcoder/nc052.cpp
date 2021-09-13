#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<char> st;
        for(auto &x: s){
            if(x == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else if(x == ']' && !st.empty() && st.top() == '[')
                st.pop();
            else if(x == '}' && !st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(x);
        }return st.empty();
    }
};