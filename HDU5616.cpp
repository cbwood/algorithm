/*************************************************************************
	> File Name: HDU5616.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月07日 星期三 10时33分40秒
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
const int maxn = 2e3 + 10;

int a[maxn], b[maxn];
int w[maxn];

void solve(int n, int sum){
    memset(a, 0, sizeof(a));
    a[w[1]] = a[0] = 1;
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j <= sum; ++j)
            for(int k = 0; j + k <= sum && k <= w[i]; k += w[i])
                b[j+k] += a[j],b[abs(j-k)] += a[j];
        for(int j = 0; j <= sum; ++j)
            a[j] = b[j], b[j] = 0;
    }
}

int main(){
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int sum = 0;
        for(int i = 1; i <= n; ++i)
            scanf("%d", w+i), sum += w[i];
        scanf("%d", &m);
        solve(n, sum);
        while(m--){
            int k;
            scanf("%d", &k);
           // printf("%d",a[k]);
            if(a[k])
                puts("YES");
            else puts("NO");
        }
    }
	return 0;
}
