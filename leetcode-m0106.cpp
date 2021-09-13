#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        string ans="";
        ans += S[0];
        int n = S.length();
        int k=0;
        int num = 1;
        for(int i = 1; i < n; i++){
            if(S[i] == S[k])
                num++;
            else{
                ans+=to_string(num);
                num=1;
                k=i;
                ans+=S[i];
            }
        }ans+=to_string(num);
        if(ans.length()<n)
            return ans;
        else return S;
    }
};

int main(){
    
    return 0;
}