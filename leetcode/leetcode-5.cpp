#include<bits/stdc++.h>
using namespace std;

const int maxn = 1002;
int dp[maxn][maxn];

void show(int n){
    printf("---------------------\n");
    for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                printf("%d ", dp[i][j]);
            printf("\n");
        }
    printf("---------------------\n");
}

class Solution {
public:
    string longestPalindrome(string s) {
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < maxn; ++i)
            dp[i][i] = 1;
        int ansx,ansy,ans;
        ansx = ansy =0;
        ans = 1;
        int len = s.length();
        for(int i = 1; i < len; ++i)
            if(s[i] == s[i-1]){
                dp[i-1][i] = 2;
                ans = 2;
                ansx = i-1;
                ansy = i;
            }
        for(int i = len-2; i >= 0; --i)
            for(int j = i+1; j < len; ++j)
                if(dp[i+1][j-1]){
                   // printf("%d %d\n", i, j);
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1]+2;
                    }
                    if(dp[i][j] > ans){
                        ans = dp[i][j];
                        ansx = i;
                        ansy = j;
                    }
                }
        // show(len);
        return s.substr(ansx, ansy-ansx+1);
    }
};

int main(){
    Solution s;
    string ss="cbbd";
    cout << s.longestPalindrome(ss)<< endl;
    return 0;

}

