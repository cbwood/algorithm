/*************************************************************************
	> File Name: HDU5936.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月13日 星期五 15时41分24秒
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
const int maxn = 1e5;

LL f[11][11];
LL h[maxn+10][11];
LL a[maxn+10];

void init(){
    for(int i = 1; i <= 9; ++i){
        f[i][0] = 1LL;
        for(int j = 1; j <= 9; ++j)
            f[i][j] = f[i][j-1] * i;
    }
    for(int i = 0; i < maxn; ++i){
        for(int j = 1; j <= 9; ++j){
            LL tmp = i;
            while(tmp){
                int t = tmp % 10;
                tmp /= 10;
                h[i][j] += f[t][j];
            }
        }
    }
}

LL solve(LL x, int k){
    LL ans = 0;
    for(int i = 0; i < maxn; ++i)
        a[i] = h[i][k] - 1LL * i * maxn;
    sort(a ,a+maxn);
    for(int i = 0; i < maxn; ++i){
        LL tmp = h[i][k] - i;
        ans += upper_bound(a, a+maxn, x-tmp) - lower_bound(a, a+maxn, x- tmp);
    }return ans - (x == 0);
}

int main(){
    int t, kase = 0;
    init();
    scanf("%d", &t);
    while(t--){
        int x, k;
        scanf("%d %d", &x, &k);
        printf("Case #%d: %lld\n", ++kase, solve(x, k));
    }
	return 0;
}
