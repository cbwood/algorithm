/*************************************************************************
	> File Name: HDU5937.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月13日 星期五 17时07分08秒
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
    int x, y, z;
}a[40];

void init(){
    int cnt = 0;
    for(int i = 1; i <= 9; ++i)
        for(int j = 1; j+i<= 9; ++j){
            a[++cnt].x = i;
            a[cnt].y = j;
            a[cnt].z = i+j;
        }
}

int num[12], ans;

void dfs(int cnt, int sum){
    if(cnt == 37){ans = max(ans, sum); return;}
    if(sum + 36 - cnt + 1 <= ans) return ;
    int x = a[cnt].x, y = a[cnt].y, z = a[cnt].z;
    if(num[x] && num[y] && num[z]){
        num[x]--,num[y]--,num[z]--;
        if(num[x]>=0 && num[y] >=0 && num[z] >= 0)dfs(cnt+1, sum+1);
        num[x]++,num[y]++,num[z]++;
    }dfs(cnt+1,sum);
}

int main(){
    int t, kase = 0;
    init();
    scanf("%d", &t);
    while(t--){
        for(int i = 1; i <= 9; ++i)
            scanf("%d",num+i);
        ans = 0;
        dfs(1, 0);
        printf("Case #%d: %d\n", ++kase, ans);
    }
	return 0;
}
