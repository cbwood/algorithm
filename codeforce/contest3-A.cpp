/*************************************************************************
	> File Name: contest3-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月29日 星期日 17时34分25秒
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
const int maxn = 1e6 + 10;

LL a[maxn];
bool vis[maxn];
LL su[maxn];
int main(){
    int m, n;
    scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i)
            scanf("%lld", a+i);
        int t, v, x, q, y ;
        LL sum = 0;
        while(m--){
            scanf("%d", &t);
            if(t == 1){
                scanf("%d %d", &v, &x);
                if(sum)
                    su[v] = -sum;
                a[v] = x;
            }else if(t == 2){
                scanf("%d", &y);
                sum += y;
            }else {
                scanf("%d", &v);
                LL ans = a[v] + su[v] + sum;
                printf("%lld\n", ans);
            }
        }
	return 0;
}
