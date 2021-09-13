/*************************************************************************
	> File Name: HDU4203.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月11日 星期三 20时56分54秒
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

LL SG(LL n) {return (n&1 ? SG(n/2) : n/2);}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        LL ans = 0;
        cin >> n;
        while(n--){
            LL x;
            cin >>  x;
            ans ^= SG(x);
        }puts(ans ? "YES" : "NO");
    }return 0;
}
