/*************************************************************************
	> File Name: LightOJ-1038.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月17日 星期二 13时55分08秒
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

double dp[maxn];

void init(){
    dp[1] = 0;
    for(int i = 2; i < maxn; ++i){
        int num = -1;
        double ans = 0;
        for(int j = 1; j*j <= i; ++j){
            if(i % j == 0){
                ans += dp[j] + 1;
                num++;
                if(j*j != i)
                    ans += dp[i/j] + 1,num++;
            }
        }dp[i] = ans / num;
    }
}

int main(){
    init();
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("Case %d: %f\n",  ++kase, dp[n]);
    }
	return 0;
}
