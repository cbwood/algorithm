/*************************************************************************
	> File Name: ZOJ-3772.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月25日 星期一 13时03分14秒
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
const int maxn = 4e5 + 10;

struct mat{
    LL a[3][3];
    mat(){memset(a, 0, sizeof(a));}
    mat(LL x){
        a[1][1] = a[2][1] = 1;
        a[2][2] = 0;
        a[1][2] = x;
    }
    mat operator *(mat q){
        mat c;
        for(int i = 1; i <= 2; ++i)
            for(int j = 1; j <= 2; ++j)
                if(a[i][j])
                for(int  k = 1; k <= 2; ++k)
                    c.a[i][k] = (c.a[i][k] + a[i][j] * q.a[j][k] % mod) % mod;
        return c;
    }
};

int ll[maxn], rr[maxn];
LL arr[maxn];
mat sum[maxn];

void build(int l, int r, int cur){
    ll[cur] = l;
    rr[cur] = r;
    if(l == r){
        sum[cur] = mat(arr[l]);
        return ;
    }
    int mid = (ll[cur] + rr[cur]) / 2;
    build(l, mid, cur<<1);
    build(mid+1, r, cur<<1|1);
    sum[cur] = sum[cur<<1|1] * sum[cur<<1]; 
}

mat query(int l, int r, int cur){
    if(ll[cur] == l && rr[cur] == r){
        return sum[cur];
    }int mid = (ll[cur] + rr[cur]) / 2;
    if(r <= mid)
        return query(l, r, cur<<1);
    if(l > mid)
        return query(l, r, cur<<1|1);
    return query(mid+1, r, cur<<1|1) * query(l, mid, cur<<1);
}

int main(){
    int n, m, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i)
            scanf("%lld", arr+i);
        build(1, n, 1);
        while(m--){
            int l, r;
            scanf("%d %d", &l, &r);
            if(r == l || r == l+1){
                printf("%lld\n", arr[r]);
                continue;
            }
            mat t = query(l+2, r, 1);
            printf("%lld\n", (t.a[1][1] * arr[l+1] + t.a[1][2] * arr[l]) % mod);
        }
    }
	return 0;
}
