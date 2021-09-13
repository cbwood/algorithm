/*************************************************************************
	> File Name: changchun-F.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月18日 星期三 19时45分20秒
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

int a[maxn];

int main(){
    int k, t, n, kase = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        int cnt = 0;
        if(k&1 && k > 1){
            a[++cnt] = k + 1;
            for(int i = 1; i <= k; ++i)
                a[++cnt] = i;
            a[++cnt] = 2 * k;
            for(int i = k+2; i <= n; ++i)
                if(i != 2 * k)
                    a[++cnt] = i;
        }else {
            for(int i = 1;i <= k; ++i)
                a[++cnt] = i;
            a[++cnt] = k * 2;
            for(int i = k+1; i <= n; ++i)
                if(i != 2 * k)
                    a[++cnt] = i;
        }
        printf("Case #%d:", ++kase);
        for(int i = 1; i <= n; ++i)
            printf(" %d", a[i]);
        printf("\n");
    }
	return 0;
}
