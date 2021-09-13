/*************************************************************************
	> File Name: codeforce-148D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月15日 星期日 10时21分48秒
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
const int maxn = 1e3 + 10;

double dp[maxn][maxn];

int main(){
    int w, b;
    scanf("%d %d", &w, &b);
    for(int i = 1; i <= max(w,b); ++i){
        dp[i][0] = 1;
        dp[i][1] = 1.0*i / (i+1);
    }for(int i = 1; i <= w; ++i)
        for(int j = 2; j <= b; ++j){
            double tmp = 1.0 * j / (i+j) * 1.0*(j-1) / (i+j-1);
            if(j > 2) dp[i][j] += tmp * (j-2) / (i+j-2) * dp[i][j-3];
            dp[i][j] += dp[i-1][j-2] * i / (i+j-2)*tmp + 1.0*i/(i+j);
        }
    printf("%.9f\n", dp[w][b]);
	return 0;
}
