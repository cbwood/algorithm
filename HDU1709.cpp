/*************************************************************************
	> File Name: HDU1709.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月02日 星期五 16时21分48秒
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
const int maxn = 1e4 + 10;

int a[maxn], b[maxn], w[maxn], ans[maxn];

int solve(int n, int sum){
    memset(a, 0, sizeof(a));
    a[w[1]] = a[0] = 1;
    for(int i = 2; i <= n ; ++i){
        for(int j = 0;j <= sum; ++j)
            for(int k = 0;k <= 1 && j + k * w[i] <= sum; ++k)
                    b[j + k * w[i]] += a[j], b[abs(j - k * w[i])] += a[j];
        for(int j = 0; j <= sum; ++j)
            a[j] = b[j], b[j] = 0;
    }
    //printf("%d\n", sum);
    int num = 0;
    for(int i = 1; i <= sum; ++i)
        if(!a[i])
            ans[++num] = i;
    return num;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int sum = 0;
        for(int i = 1; i <= n; ++i)
            scanf("%d", w + i), sum += w[i];
        int num;
        printf("%d\n", num = solve(n, sum));
        for(int i = 1; i< num; ++i)
            printf("%d ", ans[i]);
        if(num)
            printf("%d\n", ans[num]);
    }
	return 0;
}
