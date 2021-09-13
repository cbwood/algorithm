/*************************************************************************
	> File Name: HDU-3949.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月07日 星期二 14时18分46秒
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
const LL mod = 1e9 + 7;
const int maxn = 1e4 + 10;
const int MAX_BASE = 60;

LL a[maxn], b[66];
vector<LL> qq;
bool zero;

void solve(int  n) {
    int num = 0;
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; ++i)
        for (int j = MAX_BASE; j >= 0; --j)
            if (a[i] >> j & 1) {
                if (b[j]) a[i] ^= b[j];
                else {
                    b[j] = a[i];
                    num++;
                    for (int k = j - 1; k >= 0; --k)
                        if (b[k] && (b[j] >> k & 1))
                            b[j] ^= b[k];
                    for (int k = j + 1; k <= MAX_BASE; ++k)
                        if (b[k] >> j & 1)
                            b[k] ^= b[j];
                    break;
                }
            }
    if(num != n) zero = true;
    else zero = false;
    qq.clear();
    for(int i = 0; i <= MAX_BASE; ++i)
        if(b[i]) qq.emplace_back(b[i]);
}

LL gao(LL k){
    if(zero) k--;
    if(k >= (1LL<<qq.size())) return -1LL;
    LL ans = 0;
    for(int i = 0; i < qq.size(); ++i)
        if((k >> i) &1) ans ^= qq[i];
    return ans;
}

int main(){
    int t, kase = 0;
    //ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        int n,q;
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> a[i];
        cin >> q;
        cout << "Case #" << ++kase << ":" << endl;
        solve(n);
        while(q--){
            LL k;
            cin >> k;
            cout << gao(k) << endl;
        }
    }
	return 0;
}
