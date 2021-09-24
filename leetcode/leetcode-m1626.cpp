//
// Created by cb on 2021/9/24.
//

#include "string"
#include "vector"
#include "stack"
#include "algorithm"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        int k = 0;
        char op = '+';
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                k = k*10+s[i]-'0';
            }
            if((!isdigit(s[i])&&s[i] != ' ')||i==s.length()-1){
                if(op =='+')
                    num.push(k);
                else if(op == '-')
                    num.push(-k);
                else if(op == '*'){
                    int t = num.top();
                    num.pop();
                    num.push(t*k);
                }else{
                    int t = num.top();
                    num.pop();
                    num.push(t/k);
                }op = s[i];
                k=0;
            }
        }int ans = 0;
        while(num.size() > 1){
            int t1 = num.top();
            num.pop();
            int t2 = num.top();
            num.pop();
            num.push(t1+t2);
        }return num.top();
    }
};