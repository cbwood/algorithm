/*************************************************************************
	> File Name: codeforce-361B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月25日 星期三 08时46分18秒
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
    int n, k;
    scanf("%d %d", &n, &k);
    if((n==1 &&k == 1) || k >= n){
        printf("%d\n",-1);
        return 0;
    }for(int i = 1; i < n-k; ++i)
        a[i] = i+1;
    a[n-k] = 1;
    for(int i = n-k+1; i <= n; ++i) a[i] = i;
    for(int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
	return 0;
}
