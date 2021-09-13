/*************************************************************************
	> File Name: HDU1284.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月31日 星期三 15时49分59秒
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
const int maxn = 32770;
int v[]={2,3},a[maxn],b[maxn];
int solve(int sum){
    for(int i = 0; i <= sum; ++i)
        a[i] = 1;
    memset(b, 0, sizeof(b));
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j <= sum; ++j)
            for(int k = 0; j + k * v[i] <= sum; k++)
                b[k * v[i] + j] += a[j];
        memcpy(a, b, sizeof(b));
        memset(b, 0, sizeof(b));
    }return a[sum];
}

int main(){
    int n;
    solve(32767);
    while(scanf("%d", &n) != EOF)
        printf("%d\n", a[n]);
	return 0;
}
