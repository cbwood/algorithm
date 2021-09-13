/*************************************************************************
	> File Name: HYSBZ2005.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月11日 星期三 19时42分44秒
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

int pri[maxn], phi[maxn];
bool vis[maxn];
int cnt;

/*
void Mobius(){
    cnt = 0;
    for(int i = 1; i < maxn; ++i)
        phi[i] = i;
    for(int i = 2; i < maxn; ++i)
        if(!vis[i]){
            for(int j = i; j < maxn; j += i){
                vis[j] = true;
                phi[j] -= phi[j]/i;
            }
        }
}
*/

void Mobius(){
    cnt = 0;
    phi[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            phi[i] = i-1;
        }for(int j = 1; j <= cnt; ++j){
            if(i * pri[j] >= maxn) break;
            vis[i * pri[j]] = true;
            if(i % pri[j] == 0){
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
            phi[i * pri[j]] = phi[i] * (pri[j] - 1);
        }
    }for(int i = 1; i < maxn; ++i)
        phi[i] += phi[i-1];
}
int main(){
    Mobius();
    int n, m;
    scanf("%d %d", &n, &m);
    LL ans = -1LL * m * n;
    int pos;
    for(int i = 1; i <= min(n,m); i = pos + 1){
        pos = min(n/(n/i), m/(m/i));
        ans += 2LL *(phi[pos]-phi[i-1]) * (n/i) * (m/i);
    }
    printf("%lld\n", ans);
	return 0;
}
