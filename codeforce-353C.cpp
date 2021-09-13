/*************************************************************************
	> File Name: codeforce-353C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月26日 星期四 09时25分36秒
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
#define sqr(x) (x)*(x)
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int a[maxn], sum[maxn];
char s[maxn];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        sum[i] = a[i];
        if(i) sum[i] += sum[i-1];
    }
    scanf(" %s", s);
    int ans = 0;
    int t = 0;
    for(int i = 0; i < n; ++i){
        ans += (s[i] - '0') * a[i];
        if(s[i] == '1') t = i;
    }
    int tmp = 0;
    for(int i = n-1; i > 0; --i)
        if(s[i] == '1'){
            ans = max(ans, tmp + sum[i-1]);
            tmp += a[i];
        }
    printf("%d", max(sum[t-1], ans));
	return 0;
}
