/*************************************************************************
	> File Name: codeforce-497C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月13日 星期五 23时03分16秒
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
    int v,id;
    bool operator < (const ss &q)const {
        return v < q.v;
    }
}a[maxn];


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i)
        scanf("%d", &a[i].v), a[i].id = i;
    sort(a+1,a+1+n);
    int l = 1, r = 2;
    int ans = 0;
    while(r <= n && l <= n){
        while(a[l].v >= a[r].v && r <= n) r++;
        if(r > n || l > n) break;
        ans++;
        l++;
        r++;
    }cout << ans << endl;
	return 0;
}
