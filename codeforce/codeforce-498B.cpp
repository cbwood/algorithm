/*************************************************************************
	> File Name: codeforce-498B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月16日 星期一 22时42分42秒
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
    int v, id;
    bool operator <(const ss &q)const {
        return v > q.v;
    }
}a[maxn];
int b[maxn];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i].v),a[i].id = i;
    sort(a+1,a+1+n);
    int sum = 0;
    for(int i = 1; i <= k; ++i){
        sum += a[i].v;
        b[i] = a[i].id;
    }
    sort(b+1,b+1+k);
    printf("%d\n", sum);
    if(k == 1){
        printf("%d\n", n);
        return 0;
    }
    printf("%d ", b[1]);
    for(int i = 2; i < k; ++i)
        printf("%d ", b[i] - b[i-1]);
    printf("%d\n",n-b[k-1]);
	return 0;
}
