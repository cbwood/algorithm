/*************************************************************************
	> File Name: practice5-H.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月19日 星期二 19时10分07秒
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

LL a[maxn];

int main(){
    int n;
    LL k;
    //ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a,a+n);
    LL num = 0;
    int t;
    LL x, y;
    for(int i = 0; i < n; ++i){
        if(num + n < k)
            num += n;
        else {
            t = i;
            break;
        }
    }x = a[t];
    LL m = upper_bound(a,a+n,a[t]) - lower_bound(a,a+n,a[t]);
    int sx = lower_bound(a,a+n,a[t])-a;
    //cout << m << ' ' << sx << endl;
    if(1LL * sx * n + 1LL * sx * m >= k){
        k =k -  1LL * sx * n;
        for(int i = 0; i < n; ++i){
            k -= m;
            if(k <= 0){
                cout << x << ' ' << a[i] << endl;
                return 0;
            }
        }
        return 0;
    }k =k -  1LL * sx * n - 1LL * sx * m;
    //cout << k << endl;
    if(1LL * m * m >= k){
        cout << a[t] << ' ' << a[t] << endl;
        return 0;
    }
    k -= 1LL * m * m;
    t = upper_bound(a,a+n,a[t]) - a-1;
    for(int i = t + 1; i < n; ++i){
        k -= m;
        if(k <= 0){
            cout << a[t] << ' ' << a[i] << endl;
            return 0;
        }
    }
	return 0;
}
