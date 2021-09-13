/*************************************************************************
	> File Name: Hello2018-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月08日 星期一 22时52分38秒
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

LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans = ans * x;
        x = x * x;
        n >>= 1;
    }return ans;
}

int main(){
    LL n, m;
    cin >> n >> m;
    if(n >= 62) cout << m << endl;
    else cout << m % qpow(2, n) << endl;
	return 0;
}
