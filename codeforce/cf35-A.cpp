/*************************************************************************
	> File Name: cf35-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月28日 星期四 21时49分09秒
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

int a[maxn];

int main(){
    int n, minx = 1e9;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        cin >> a[i], minx = min(minx, a[i]);
    int ans = n, t = 0;
    for(int i = 1; i <= n; ++i)
    if(a[i] == minx){
        if(t)
        ans = min(ans, i - t);
        t = i;
    }cout << ans << endl;
	return 0;
}
