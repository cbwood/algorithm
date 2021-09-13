/*************************************************************************
	> File Name: HDU4371.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月02日 星期一 20时31分36秒
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

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n, m, maxi = 0x3f3f3f3f;
        scanf("%d %d", &n, &m);
        while(m--){
            int x;
            scanf("%d", &x);
            maxi = min(maxi, x);
        }
        n /= maxi;
        printf("Case #%d: ", ++kase);
        if(!(n&1)) puts("Alice");
        else puts("Bob");
    }
	return 0;
}
