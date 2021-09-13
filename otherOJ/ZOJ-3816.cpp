/*************************************************************************
	> File Name: ZOJ-3816.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月15日 星期日 08时25分09秒
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

int bits[20];
int L[20], R[20];
LL n;

LL check(int l, int r){
    /*for(int i = 0; i < l; ++i)
        printf("%d",L[i]);
    for(int j = r-1; j >= 0; --j)
        printf("%d",R[j]);
    printf("\n");*/
    LL ans = 0;
    for(int i = 0;  i < l; ++i) ans = ans * 10 + L[i];
    for(int j = r-1; j >= 0; --j) ans = ans * 10 + R[j];
    return ans;
}

LL dfs(int l, int r, bool limit, int len){
    if(l + r >= len){
        LL t = check(l,r);
        if(t < n) return t;
        return -1;
    }
    LL ans = -1;
    int up = limit ? bits[l] : 9;
    for(int i = up; i >= 0; --i){
        L[l] = i;
        if((l == 0 || L[l] != L[l-1]) && (l + r+1 < len) && !(i == 0 && l == 0)){
            for(int j = 0; j+l+r+2 <= len; ++j){
                R[j+r] = i;
                ans = max(ans, dfs(l+1,r+j+1, limit && i == up, len));
            }
        }else ans = max(ans, dfs(l+1, r, limit && i == up, len));
        if(ans > 0) return ans;
    }return ans;
}

LL solve(LL x){
    int pos = 0;
    while(x){
        bits[pos++] = x%10;
        x /= 10;
    }reverse(bits, bits+pos);
    return dfs(0,0,1, pos);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld" ,&n);
        printf("%lld\n",solve(n));
    }
	return 0;
}
