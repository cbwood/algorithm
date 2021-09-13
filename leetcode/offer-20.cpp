#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(char s){
        if(s == 'e') return true;
        if(s == '.') return true;
        if(s == '+') return true;
        if(s == '-') return true;
        if(s == 'E') return true;
        if(s>= '0' && s <= '9') return true;
        return false;
    }
    bool isNumber(string s) {
        int len = s.length();
        if(len == 0) return false;
        if(s[0] == '.' || (s[0]<= '0'||s[0]>='9')&&(s[0] != '+' && s[0] != '-')) return false;
        int numdot = 0, nume=0;
        for(int i = 1; i < len; ++i){
            if(check(s[i])){
                if(s[i] == '.')
                    numdot++;
                if(s[i] == 'e' || s[i] == 'E')
                    nume++;
                if(numdot > 1 || nume > 1) return false;
                if(((s[i] == 'e' || s[i] == 'E')&&(s[i-1]<'0'||s[i-1]>'9')))
                    return false;
                if((s[i] == '-' || s[i] == '+')&&(s[i-1]=='e'||s[i-1]=='E'||s[i-1] == '-' || s[i-1] == '+'))
                    return false;    
            }else return false;
        }return true;
    }
};

int main(){
    Solution so;
    string s ="3.1";
    cout << so.isNumber(s)<<endl;
    return 0;
}