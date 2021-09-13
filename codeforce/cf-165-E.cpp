/*************************************************************************
	> File Name: cf-165-E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月20日 星期三 19时02分16秒
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
const int N = 1<<22;
int dp[N+10], a[maxn];

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int x;
        scanf("%d", &a[i]);
        dp[a[i]] = a[i];
    }for(int i = 0; i < N; ++i)
        if(dp[i] == -1){
            for(int j = 0; j <= 22; ++j)
            if(i & (1 << j) && dp[i^(1<<j)] != -1){
                dp[i] = dp[i^(1<<j)];
                break;
            }
        }
    for(int i = 1; i < n; ++i)
        printf("%d ", dp[(N-1)^a[i]]);
    printf("%d\n", dp[(N-1)^a[n]]);
	return 0;
}
