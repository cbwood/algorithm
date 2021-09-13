/*************************************************************************
	> File Name: contest8-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月04日 星期四 19时18分59秒
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


int main(){
    LL k, b, n, t;
    cin >> k >> b >> n >> t;
    LL num = 0;
    LL tt = 1;
    while(tt < t && num <= n){
        tt = tt * k + b;
        num++;
    }LL ans;
    if(t == tt) ans = n - num;
    else ans = n - num + 1;

    cout << ans << endl;
    return 0;
}

