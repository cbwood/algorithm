/*************************************************************************
	> File Name: HDU2841.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月31日 星期二 15时52分30秒
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
#define sqr(x) (x)*(x)
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 10;

LL pri[maxn], fac[maxn];
bool vis[maxn];
int cnt;

void init(){
    cnt = 0;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] < maxn; ++ j){
            vis[i*pri[j]] == 1;
            if(i % pri[j] == 0) break;
        }
    }
}

int getf(int n){
    int t = 0;
    for(int i = 1; i <= cnt && pri[i] * pri[i] <= n; ++i){
        if(n % pri[i] == 0){
            fac[t++] = pri[i];
            while(n % pri[i] == 0) n /= pri[i];
        }
    }if(n > 1) fac[t++] = n;
    return t;
}

int main(){
    init();
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        LL ans = m;
        for(int i = 2; i <= n; ++i){
            int t = getf(i);
            for(int j = 0; j < (1 << t); ++j){
                int s = 1;
                LL tmp = 1;
                for(int k = 0; k < t; ++k)
                if(j&(1<<k)){
                    s++;
                    tmp *= fac[k];
                }if(s&1) ans += m/tmp;
                else ans -= m/tmp;
            }
        }printf("%lld\n", ans);
    }
	return 0;
}
