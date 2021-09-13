/*************************************************************************
	> File Name: practice5-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月19日 星期二 20时57分49秒
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

int a[maxn][50], b[maxn];
LL euler[maxn];
int p[maxn][15];
int cnt[maxn];
bool vis[maxn];

void init()
{
        for(int i=1;i<maxn;++i)
            euler[i]=i;
        for(int i=2;i<maxn;++i)
             if(euler[i]==i){
                euler[i]=i-1;
                for(int j=i<<1;j<maxn;j+=i)
                    euler[j]=euler[j]-euler[j]/i,p[j][cnt[j]++]=i;
                
            }
        for(int i = 1; i < maxn; ++i)
            p[i][cnt[i]++] = i;
         for(int i=2;i<maxn;++i)
            euler[i]+=euler[i-1];

}
int main(){
    int n, m;
    init();
    scanf("%d %d", &n, &m);
    while(m--){
        char op;
        int k;
        scanf(" %c %d", &op, &k);
        if(op == '-'){
            if(!vis[k])
                puts("Already off");
            else {
                for(int i = 0; i < cnt[k]; ++i)
                    b[p[k][i]] = 0;
                puts("Success");
                vis[k] = false;
            }
        }else {
            if(vis[k])
                puts("Already on");
            else {
                int ans = 0;
                for(int i = 0; i < cnt[k] && !ans;++i)
                    ans = b[p[k][i]];
                if(!ans){
                for(int i = 0; i < cnt[k]; ++i)
                    b[p[k][i]] = k;
                puts("Success");
                vis[k] = true;
            }else printf("Conflict with %d\n", ans);
        }
    
        }}

	return 0;
}
