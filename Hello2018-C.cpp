/*************************************************************************
	> File Name: Hello2018-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月08日 星期一 23时15分27秒
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

struct ss{
    LL x ,y;
    bool operator <(ss &q){
        return y * q.x > x * q.y;
    }
}a[32];

int main(){
    int n;
    LL L;
    cin >> n >> L;
    LL ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i].y;
        a[i].x = 1 << i;
    }
    sort(a,a+n);
    LL ans1 = 1e18;
    for(int i = 0; i < n; ++i)
        if(a[i].x >= L)
            ans1 = min(ans1, a[i].y);
    ans = a[n-1].y * (ceil(L*1.0 / a[n-1].x));
    LL num = a[n-1].x *(ceil(L*1.0/a[n-1].x));
    LL tmp, tmpp;
    int pre = n-1;
    for(int i = n-2; i >= 0; --i){
        tmp = num - a[pre].x;
        tmpp = ans - a[pre].y;
        while(tmp < L){
            tmpp += a[i].y;
            tmp += a[i].x;
        }if(ans > tmpp){
            pre = i;
            ans = tmpp;
            num = tmp;
        }
    }cout << min(ans,ans1) << endl;
	return 0;
}
