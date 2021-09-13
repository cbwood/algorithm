/*************************************************************************
	> File Name: contest9-E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月24日 星期日 20时48分27秒
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

int w[15][305], v[15][305], cnt[15];
int dp[50000+10];

int main(){
    map<string, int > q;
    q["Head"] = 1, q["Shoulder"]=2;
    q["Neck"] = 3, q["Torso"] = 4;
    q["Hand"] = 5, q["Wrist"] = 6;
    q["Waist"] = 7, q["Legs"] = 8;
    q["Feet"] = 9, q["Finger"] = 14;
    q["Shield"] = 11, q["Weapon"] = 12;
    q["Two-Handed"] = 13;
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        memset(cnt, 0, sizeof(cnt));
        while(n--){
            string s;
            cin >> s;
            scanf("%d %d", &w[q[s]][++cnt[q[s]]], &v[q[s]][cnt[q[s]]]);
        }
        for(int i = 1; i <= cnt[14]; ++i)
            for(int j = 1; j < i; ++j)
                w[10][++cnt[10]] = w[14][i] + w[14][j], v[10][cnt[10]] = v[14][i] + v[14][j];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= 12; ++i)
            for(int M = 0; M <= m; ++M)
                if(dp[M] != -1)
                for(int j = 1; j <= cnt[i]; ++j){
                    dp[min(m, M + v[i][j])] = max(dp[min(m, M+v[i][j])], dp[M] + w[i][j]);
                }
        int ans = dp[m];
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= 13; ++i)
            if(i != 11 && i != 12)
            for(int k = 0; k <= m; ++k)
                if(dp[k] != -1)
                for(int j = 1; j <= cnt[i]; ++j)
                        dp[min(m, k+v[i][j])] = max(dp[min(m,k+v[i][j])], dp[k] + w[i][j]);
        ans = max(ans, dp[m]);
        if(ans == 0)
            ans = -1;
        printf("%d\n", ans);
    }
	return 0;
}
