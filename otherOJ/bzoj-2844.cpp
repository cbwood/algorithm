/*************************************************************************
	> File Name: bzoj-2844.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月07日 星期二 18时33分58秒
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
const LL mod = 10086;
const int maxn = 1e5 + 10;
const int MAX_BASE = 31;

int a[maxn], b[MAX_BASE + 10], num;
vector<int > vec;

LL qpow(LL x, LL n){
    LL ans = 1;
    x %= mod;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

void solve(int n) {
    memset(b, 0, sizeof b);
    for (int i = 0; i < n; ++i)
        for (int j = MAX_BASE; j >= 0; --j)
            if (a[i] >> j & 1) {
                if (b[j]) a[i] ^= b[j];
                else {
                    num++;
                    b[j] = a[i];
                    for (int k = j - 1; k >= 0; --k)
                        if (b[k] && (b[j] >> k & 1))
                            b[j] ^= b[k];
                    for (int k = j + 1; k <= MAX_BASE; ++k)
                        if (b[k] >> j & 1)
                            b[k] ^= b[j];
                    break;
                }
            }
    for(int i = 0; i <= MAX_BASE; ++i)
        if(b[i]) vec.push_back(i);
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int q;num=0;
    solve(n);
    cin >> q;
    int ans = 0;
    for(int i = 0; i < vec.size(); ++i)
        if((q >> vec[i])&1) ans += 1 << i;
    cout << (ans % mod * qpow(2,n-num) % mod+1)%mod << endl;
	return 0;
}
