/************************************************************************
	> File Name: CF-184D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月20日 星期三 18时47分19秒
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
const int maxn = 1e3 + 10;
double dp[maxn][maxn];

void init(){
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 1; i < maxn; ++i){
        dp[0][i] = 0.0;
        dp[i][1] = 1.0 * i / (i + 1);
        dp[i][0] = 1.0;
    }
    for(int i = 1; i < maxn; ++i)
        for(int j = 2; j < maxn; ++j){
            double tmp = 1.0 * j / (i + j) * (j - 1) / (i + j - 1);
            if(j > 2)
                dp[i][j] = dp[i][j] + tmp * dp[i][j-3] * (j-2) / (i + j - 2);
            dp[i][j] = dp[i][j] + tmp * dp[i-1][j-2] * i / (i + j - 2) +1.0 * i / (i + j);
        }
} 

int main(){
    int w, b;
    init();
    while(cin >> w >> b)
        printf("%.9f\n", dp[w][b]);
    return 0;
}
