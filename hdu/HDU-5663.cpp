/*************************************************************************
	> File Name: HDU-5663.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月03日 星期五 13时39分50秒
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
const int maxn = 1e7 + 10;

int mu[maxn], pri[maxn], sum[maxn];
bool vis[maxn];
int cnt;

void Mobius(){
    cnt = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
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
    	}
    }
    int t = sqrt(maxn);
    for(int i = 1; i <= t; ++i){
        int x = i * i;
        for(int j = x, k = 1; j < maxn; j+= x, ++k)
            sum[j] += mu[k];
    }for(int i = 1; i < maxn; ++i)
        sum[i] += sum[i-1];
}

LL solve(int b, int d){
    LL ans = 0, pos;
    for(int i = 1; i <= b; i = pos+1){
        pos = min(b/(b/i), d/(d/i));
        ans += 1LL * (b/i) * (d/i) * (sum[pos] - sum[i-1]);
    }return ans;
}

int main(){
    Mobius();
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        LL ans = 1LL*n*m;
        if(n > m) swap(n, m);
        ans -= solve(n, m);
        printf("%lld\n", ans);
    }
	return 0;
}
