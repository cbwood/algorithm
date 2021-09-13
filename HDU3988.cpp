/*************************************************************************
	> File Name: HDU3988.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月21日 星期六 11时18分02秒
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
const int maxn = 1e7 + 10;

vector<LL> pri,fac;
bool vis[maxn];

void init(){
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]) pri.emplace_back(i);
        for(auto x : pri){
            if(x*i >= maxn) break;
            vis[i*x] = 1;
            if(i%x == 0) break;
        }
    }
}

LL getfac(LL n, LL k){
    LL ans = 0;
    while(n){
        n /= k;
        ans += n;
    }return ans;
}

LL get(LL n, LL k){
    LL ans = 0;
    while(n % k == 0){
        n /= k;
        ans++;
    }return ans;
}

void getf(LL n){
    fac.clear();
    for(auto x : pri){
        if(x > n) break;
        if(n%x == 0){
            fac.emplace_back(x);
            while(n%x == 0) n /= x;
        }
    }if(n > 1) fac.emplace_back(n);
}

int main(){
    init();
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        LL n,k;
        scanf("%lld %lld", &n, &k);
        LL ans = 0x3f3f3f3f3f3f3f3f;
        if(k == 1){
            printf("Case %d: ", ++kase);
            puts("inf");
            continue;
        }
        getf(k);
        for(auto x : fac){
            LL tmp = getfac(n, x);
            LL t = get(k, x);
            ans = min(ans,tmp/t);
            if(ans == 0) break;
        }
        printf("Case %d: %lld\n", ++kase, ans);
    }
	return 0;
}
