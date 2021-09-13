/*************************************************************************
	> File Name: SGU495.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月27日 星期三 20时09分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define sqr(x) ((x)*(x))
using namespace std;

typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;

double dp[maxn];

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        dp[1] = 1;
        for(int i = 2; i <= m; ++i)
            dp[i] = dp[i-1] + (n-dp[i-1]) / n ;
        printf("%.9f\n", dp[m]);
    }return 0;
}
