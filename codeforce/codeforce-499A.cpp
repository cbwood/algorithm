/*************************************************************************
	> File Name: codeforce-499A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月26日 星期四 22时31分52秒
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

int a[maxn];

int main(){
    int n, m;
    scanf("%d %d" ,&n, &m);
    int ans = 100000;
    for(int i = 1; i <= m; ++i){
        int x;
        scanf("%d", &x);
        a[x]++;
        ans = min(ans, a[x]);
    }
    ans = 0;
    int k = m/n;
    while(k){
        int num = 0;
        for(int i = 1; i <= 100; ++i)
        if(a[i] >= k){
            num += a[i]/k;
        }if(num >= n)
            break;
        k--;
    }printf("%d\n", k);
}
