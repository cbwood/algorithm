/*************************************************************************
	> File Name: codeforce-237C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月25日 星期三 18时14分08秒
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
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;

bool vis[maxn];
int sum[maxn];
vector<int> pri;
int a,b,k;

void init(){
    sum[1] = 0;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri.emplace_back(i);
            sum[i] = sum[i-1] + 1;
        }else sum[i] = sum[i-1];
        for(auto x : pri){
            if(x*i >= maxn) break;
            vis[i*x] = 1;
            if(i%x == 0) break;
        }
    }
}

bool check(int l){
    for(int i = a; i <= b-l+1; i++)
        if(sum[i+l-1] - sum[i-1] < k) return false;
    return true;
}

int main(){ 
    init();
    scanf("%d %d %d", &a, &b, &k);
    int l = 1, r = b-a+1, ans = -1;
    while(l <= r){ 
        int mid = (l+r) >> 1;
        if(check(mid))
            r = mid - 1, ans = mid;
        else l = mid + 1;
    }printf("%d\n", ans);
	return 0;
}
