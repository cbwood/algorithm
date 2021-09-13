/*************************************************************************
	> File Name: bzoj-2120.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月04日 星期六 09时06分44秒
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

struct ask{
    int l, r, id, tim, bl, rl;
    ask(int l=0, int r=0, int id=0, int tim=0, int bl=0, int rl = 0)
    :l(l), r(r),id(id), tim(tim),bl(bl), rl(rl){};
    bool operator < (const ask &rhq)const{
        if(bl != rhq.bl) return bl < rhq.bl;
        if(rl != rhq.rl) return rl < rhq.rl;
        return tim < rhq.tim;
    }
}que[maxn];

struct modify{
    int x, y, pre;
    modify(int x=0, int y=0, int pre = 0)
    :x(x), y(y), pre(pre){};
}mo[maxn];

int a[maxn], last[maxn];
int num[maxn*100];

int tmp;
int ans[maxn];

inline void del(int x){
    num[a[x]]--;
    if(num[a[x]] == 0) tmp--;
}

inline void add(int x){
    num[a[x]]++;
    if(num[a[x]] == 1) tmp++;
}

inline void upd(int x, int y, int l, int r){
    if(l <= x && x <= r){
        del(x);
        a[x] = y;
        add(x);
    }else a[x] = y;
}

int main(){
    int n, m;
    scan_d(n);
    tmp = 0;
    scan_d(m);
    for(int i = 1; i <= n; ++i)
        scan_d(a[i]), last[i] = a[i];
    int cnt1 = 0, cnt2 = 0;
    int sz = sqrt(n);
    while(m--){
        char op;
        int x,y;
        scanf(" %c", &op);
        scan_d(x);
        scan_d(y);
        if(op == 'Q'){++cnt1;
            que[cnt1] = ask(x,y,cnt1,cnt2,(x-1)/sz+1, (y-1)/sz+1);
        }else mo[++cnt2] = modify(x, y, last[x]), last[x] = y;
    }sort(que+1,que+1+cnt1);
    int l = 1, r= 0,ti = 0;
    for(int i = 1; i <= cnt1; ++i){
        while(l < que[i].l) del(l),l++;
        while(l > que[i].l) l--, add(l);
        while(r > que[i].r) del(r), r--;
        while(r < que[i].r) r++,add(r);
        while(ti < que[i].tim) ti++, upd(mo[ti].x, mo[ti].y,l ,r);
        while(ti > que[i].tim) upd(mo[ti].x, mo[ti].pre, l,r), ti--; 
        ans[que[i].id] = tmp;
    }
    for(int i = 1; i <= cnt1; ++i)
        out(ans[i]),puts("");
	return 0;
}
