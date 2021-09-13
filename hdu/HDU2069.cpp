/*************************************************************************
	> File Name: HDU2069.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月05日 星期一 22时40分41秒
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

int v[] = {0, 1, 5, 10, 25, 50};
int a[260][102], b[260][102];

void solve(int sum){
    for(int i = 0; i <= 100; ++i)
        for(int j = 0 ;j <=sum;  ++j)
            if(j <= i)
            a[j][i] = 1;
    for(int i = 2; i <= 5; ++i){
        for(int p = 0; p <= 100; ++p)
        for(int j = 0; j <= sum; ++j)
            for(int k = 0; k * v[i] + j <= sum && k + p<=100; k++)
                b[j+k * v[i]][k+p] += a[j][p];
        memcpy(a, b, sizeof(b));
        memset(b, 0, sizeof(b));
    }return ;
}

int main(){
    int n;
    solve(250);
    while(scanf("%d", &n) != EOF){
        int ans = 0;
        for(int i = 0; i <= 100; ++i)
            ans = max(ans, a[n][i]);
        printf("%d\n", ans);
    }
	return 0;
}
