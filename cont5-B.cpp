/*************************************************************************
	> File Name: cont5-B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月21日 星期四 19时22分33秒
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
int a[maxn];

int main(){
    int n, x;
    int ans = 1;
    scanf("%d %d", &n, &x);
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    sort(a+1,a+1+n);
    int l = lower_bound(a+1,a+1+n, x) - a;
    if(a[l] == x)
        ans = 0;
    int r = upper_bound(a+1,a+1+n,x) - a-1;
    int k = (n +1) / 2;
    if(x > a[n] || x < a[1])
    ans += n + (x < a[1] ? -1 : 0);
    else if(l <= k && r >= k)
        ans = 0;
    else {
        if(ans) n++, r++;
        k = (n + 1) / 2;
        //cout << l << ' ' << r <<' ' << k << endl;
        if(r < k){
            ans += n - r - r ;
        }else if(l > k)
        ans += l + l - n  - 1;
    }
    printf("%d\n", ans);
	return 0;
}
