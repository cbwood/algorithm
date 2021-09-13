/*************************************************************************
	> File Name: luogu-P1972.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月03日 星期五 19时38分18秒
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
const int maxn = 5e5 + 10;

int pos[maxn];
struct ss{
    int l, r, id, bl;
    bool operator <(const ss &rhq)const{
        if(bl == rhq.bl) return r < rhq.r;
        return bl < rhq.bl;
    }
}q[maxn/2];

int a[maxn];
int num[maxn*2];
int ans[maxn];
int tmp;

template <class T>
inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c = getchar(),c == EOF) return 0; //EOF
    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c-'0');
    while(c = getchar(),c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
inline void out(int x) {
	if(x > 9) out( x / 10);
	putchar( x % 10 + '0');
}

inline void del(int x){
    num[a[x]]--;
    if(num[a[x]] == 0) tmp--;
}

inline void add(int x){
    num[a[x]]++;
    if(num[a[x]] == 1) tmp++;
}

int main(){
    int n;
    scan_d(n);
    for(int i = 1; i <= n; ++i){
        scan_d(a[i]);
    }int m;tmp = 0;
    scan_d(m);
    int sz = sqrt(n);
    for(int i = 1; i <= m; ++i){
        scan_d(q[i].l);
        scan_d(q[i].r);
        q[i].id = i;
        q[i].bl = q[i].l/sz;
    }
    int l = 1, r = 0;
    sort(q+1,q+1+m);
    for(int i = 1; i <= m; ++i){
        while(l < q[i].l) del(l),l++;
        while(l > q[i].l) l--,add(l);
        while(r < q[i].r) r++,add(r);
        while(r > q[i].r) del(r),r--;
        ans[q[i].id] = tmp;
    }for(int i = 1; i <= m; ++i)
        out(ans[i]),puts("");
	return 0;
}
