/*************************************************************************
	> File Name: codeforce645E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年03月01日 星期四 17时16分38秒
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
const int maxn = 1e7 + 10;

LL sum[30];
char ss[maxn];
int pos[30];

int main(){
    int n, k;
    while(scanf("%d %d %s", &n, &k, ss) != EOF){
        int len = strlen(ss);
        LL ans = 1;
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < len; ++i){
            int t = ss[i] - 'a';
            LL pre = ans;
            ans = ((ans * 2 - sum[t]) % mod + mod) % mod;
            sum[t] = pre;
            pos[t] = i + 1;
        }
        for(int i = 0; i < n; ++i){
            int x = maxn, y = 0;
            for(int j = 0; j < k; ++j)
                if(pos[j] < x){
                    x = pos[j];
                    y = j;
                }
            LL pre = ans;
            ans = ((ans * 2 - sum[y]) % mod + mod) % mod;
            sum[y] = pre;
            pos[y] = i+1+len;
        }
        printf("%lld\n", (ans % mod + mod) % mod);
    }
	return 0;
}
