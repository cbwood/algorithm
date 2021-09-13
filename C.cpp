#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
const int maxn = 30000+10;
int a[maxn], tmp[maxn], b[maxn];
int ans;


void Merge_sort(int l, int r){
    if(r - l <= 1) return ;
    int m = (l + r) >> 1;
    Merge_sort(l, m);
    Merge_sort(m, r);
    int x = l, y = m, i = l;
    while(x < m ||y < r){
        if(y >= r ||(x < m && a[x] <= a[y]))
            tmp[i++] = a[x++];
        else {
            tmp[i++] = a[y++];
            ans += m - x ;
        }
    }for(i  = l ; i< r; ++i)
        a[i] = tmp[i];
}


LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

LL f(LL n){
    LL ans = 1;
    while(n--){
        ans = ans * (n+1)% mod;
    }return ans;
}

int main(){
    int n;
    while(cin >> n){
        ans = 0;
        for(int i = 0; i < n; ++i)
            b[i] = i;
        do{
            for(int i = 0; i < n; ++i)
                a[i] = b[i];
            Merge_sort(0,n);
        }while(next_permutation(b,b+n));
        cout << ans * qpow(f(n), mod-2) % mod<< endl;
    }return 0;
}
