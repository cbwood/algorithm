/*************************************************************************
	> File Name: codeforce-498C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月16日 星期一 23时04分58秒
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

map<LL,int> q;
int a[maxn*2];

int main(){
    int n;
    scanf("%d", &n);
    LL sum = 0;
    for(int i = 1; i <= n; ++i){
        int x;
        scanf("%d", &x);a[i] = x;
        sum += x;
        q[sum] = i;
    }
    LL sumt = 0, ans = 0;
    for(int i = n; i >= 1; --i){
        sumt += a[i];
        q[sum] = 0;
        sum -= a[i];
        if(q[sumt])
        {
            ans = max(ans, sumt);
        }
    }cout << ans << endl;
	return 0;
}
