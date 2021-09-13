/*************************************************************************
	> File Name: POJ3046.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月08日 星期四 15时50分38秒
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
const int mod = 1e6;
const int maxn = 1e5 + 10;

int a[maxn],b[maxn], num[maxn];

void solve(int n, int sum){
    memset(a, 0, sizeof(a));
    for(int i = 0; i <= num[1]; ++i)
        a[i] = 1;
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j <= sum; ++j)
            for(int k = 0; k <= num[i] && k + j <= sum; ++k)
                b[j+k] += a[j];
        for(int j = 0; j <= sum; ++j)
            a[j] = b[j] % mod, b[j] = 0;
    }
}

int main(){
    int T, S, A, B;
    while(scanf("%d %d %d %d", &T, &A, &S, &B) != EOF){
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= A; ++i){
            int x;
            scanf("%d", &x);
            num[x]++;
        }solve(T, A);
        LL ans = 0;
        for(int i = S; i <= B; ++i)
            ans += a[i];
        printf("%lld\n", ans % mod);
    }
	return 0;
}
