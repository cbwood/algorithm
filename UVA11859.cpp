/*************************************************************************
	> File Name: UVA11859.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月14日 星期六 10时36分44秒
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

int pri[maxn];

void init(){
    for(int i = 2; i < maxn; ++i)
        if(!pri[i]){
            int t = i;
            while(t < maxn){
                for(int j = t; j < maxn; j += t)
                    pri[j]++;
                t *= i;
            }
        }
}

int main(){
    int t, kase = 0;
    init();
    scanf("%d", &t);
    while(t--){
        int n, m, k;
        int ans = 0;
        scanf("%d %d", &n, &m);
        k = m;
        while(n--){
            int tmp = 0;
            m = k;
            while(m--){
                int x;
                scanf("%d", &x);
                tmp += pri[x];
            }
            ans ^= tmp;
        }
        printf("Case #%d: %s\n", ++kase , (ans ? "YES" : "NO"));
    }
	return 0;
}
