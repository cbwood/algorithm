/*************************************************************************
	> File Name: HDU1262.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月20日 星期五 22时33分34秒
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

vector<int> pri;
bool vis[maxn];

void init(){
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]) pri.emplace_back(i);
        for(auto x : pri){
            if(i*x > maxn) break;
            vis[i*x] = 1;
            if(i%x == 0) break;
        }
    }
}

int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF){
        int ansx, ansy, minx = 0x3f3f3f3f;
        for(auto x : pri){
            if(x >= n) break;
            int tmp = n - x;
            int t = lower_bound(pri.begin(),pri.end(), tmp) - pri.begin();
            if(abs(pri[t] - x) < minx && pri[t] == tmp){
                ansx = x;
                ansy = pri[t];
                minx = abs(pri[t]-x);
            }
        }printf("%d %d\n", ansx, ansy);
    }
	return 0;
}
