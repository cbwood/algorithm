/*************************************************************************
	> File Name: changchun-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月18日 星期三 18时50分31秒
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

int a[30] = {0, 0, 0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14};

int main(){
    int t, n, kase = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("Case #%d: %d\n",++kase, a[n]);
    }
	return 0;
}
