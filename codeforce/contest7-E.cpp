/*************************************************************************
	> File Name: contest7-E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月02日 星期二 18时26分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<string>

using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int w[30][30], dp[30][30];

int main(){
    int n;
    string s;
    ios::sync_with_stdio(0);
    cin >> n;
    memset(w, 0, sizeof(w));
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    while(n--){
        cin >> s;
        int len = s.length();
        int a = s[0] - 'a', b = s[len-1] -'a';
        for(int i = 0; i < 26; ++i)
            if(dp[i][a] || i == a)
                dp[i][b] = max(dp[i][b], dp[i][a] + len);
    }
    for(int i = 0; i < 26; ++i)
            ans = max(ans, dp[i][i]);
    cout << ans << endl;
	return 0;
}
