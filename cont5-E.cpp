/*************************************************************************
	> File Name: cont5-E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月21日 星期四 19时15分47秒
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
const int maxn = 1e7 + 10;

LL f[maxn];

int main(){
    int n;
    scanf("%d", &n);
    f[0] = f[1] = 0;
    f[2] = 3;
    f[3] = 6;
    for(int i = 4; i <= n; ++i)
        f[i] = (f[i-1] * 2 + f[i-2] * 3) % mod;
    cout << f[n] << endl;
	return 0;
}
