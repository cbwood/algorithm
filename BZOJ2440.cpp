/*************************************************************************
	> File Name: BZOJ2440.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月13日 星期二 09时57分59秒
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

int pri[maxn], mu[maxn];
bool vis[maxn];

void Mobius(){
    int cnt = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1;
        }
        for(int j = 1; j <= cnt && i * pri[j] < maxn; ++j){
            vis[i*pri[j]] = true;
            if(i % pri[j] == 0){
                mu[i*pri[j]] = 0;
                break;
            }mu[i*pri[j]] = - mu[i];
        }
    }
}

bool check(int n, int k){
    int ans = 0;
    for(int i = 1; i * i <= n; ++i)
        ans += n / (i*i) * mu[i];
    return ans >= k;
}

int main(){
    int t;
    Mobius();
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int l = 1, r = n << 1, ans;
        while(l <= r){
            int mid = (r - l) / 2 + l;
            if(check(mid, n)) r = mid - 1, ans = mid;
            else l = mid + 1;
        }printf("%d\n", ans);
    }
	return 0;
}
