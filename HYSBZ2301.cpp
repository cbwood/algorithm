/*************************************************************************
	> File Name: HYSBZ2301.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月10日 星期二 21时35分16秒
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

int pri[maxn], mu[maxn], sum[maxn];
bool vis[maxn];
int cnt;

void Mobius(){
    cnt = 0;
    mu[1] = 1;
    sum[1] = 1;
    for(int  i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1;
        }for(int j = 1; j <= cnt; ++j){
            if(i * pri[j] >= maxn) break;
            vis[i * pri[j]] = true;
            if(i % pri[j]== 0){
                mu[i * pri[j]] = 0;
                break;
            }mu[i * pri[j]] = - mu[i];
        }sum[i] = sum[i-1] + mu[i];
    }
}

LL solve(int b, int d){
    if(b > d) swap(b, d);
    LL ans = 0, pos;
    for(int i = 1; i <= b; i = pos+1){
        pos = min(b/(b/i), d/(d/i));
        ans += 1LL * (b/i) * (d/i) *(sum[pos] - sum[i-1]);
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    Mobius();
    while(t--){
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        LL ans = solve(b/k, d/k) - solve((a-1)/k, d/k) - solve((c-1)/k,b/k) + solve((a-1)/k,(c-1)/k);
        printf("%lld\n", ans);
    }
	return 0;
}
