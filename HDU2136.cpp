/*************************************************************************
	> File Name: HDU2136.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月20日 星期五 22时45分18秒
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
const int maxn = 1e6 + 10;

vector<int> pri;
bool vis[maxn];
int a[maxn];

void init(){
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]) pri.emplace_back(i);
        for(auto x : pri){
            if(x*i >= maxn) break;
            vis[i*x] = 1;
            if(i % x == 0) break;
        }
    }
}

int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF){
        int ans = 0;
        int m = n;
        if(!a[n] && n > 1){
            for(int i =0; i < pri.size() && pri[i]*pri[i]  <= m; ++i)
                if(m % pri[i] == 0){
                    ans = max(ans, pri[i]);
                    while(m % pri[i] == 0) m /= pri[i];
                }
            if(m > 1) ans = max(ans, m);
            a[n] = lower_bound(pri.begin(), pri.end(), ans) - pri.begin()+1;
        }
        printf("%d\n", a[n]);
    }
	return 0;
}
