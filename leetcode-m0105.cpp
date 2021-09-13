#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    bool oneEditAway(string first, string second) {
        int dp[105][105]={0};
        int n = first.length();
        int m = second.length();
        for(int i = 0; i < n; i++)
            dp[i+1][0] = i+1;
        for(int j = 0; j < m; j++)
            dp[0][j+1] = j+1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(first[i] != second[j])
                    dp[i+1][j+1] = min(dp[i][j+1]+1, min(dp[i+1][j]+1, dp[i][j]+1));
                else dp[i+1][j+1] = dp[i][j]; 
            }
            return dp[n][m]<=1;
    }
};

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.length();
        int m = second.length();
        if(abs(n-m) > 1) return false;
        if(n == m){
            int num = 0;
            for(int i = 0; i < n; i++){
                if(first[i] != second[i])
                    num++;
                if(num > 1) return false;
            }
        }else if(n>m){
            int k=0;
            for(int i = 0; i < m;i++){
                if(second[i] != first[i+k] && k)
                    return false;
                if(second[i] != first[i+k]){
                    k++;i--;
                }
            }
        }else if(n<m){
            int k=0;
            for(int i = 0; i < n;i++){
                if(second[i+k] != first[i] && k)
                    return false;
                if(second[i+k] != first[i]){
                    k++;i--;
                }
            }
        }return true;
    }
};


int main(){
    Solution so;
    string a="ab";
    string b ="bc";
    bool aa = so.oneEditAway(a, b);
    cout<<aa<<endl;
    return 0;
}