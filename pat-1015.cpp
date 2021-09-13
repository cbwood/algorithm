#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
typedef long long LL;
bool vis[maxn];
int pri[maxn];

void prime(){
    int cnt = 0;
    vis[0] = vis[1] = true;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; pri[j] * i < maxn && j <= cnt; ++j){
            vis[i*pri[j]] = 1;
            if(i%pri[j] == 0) break;
        }
    }
}

LL convert(LL a, LL d){
    LL ans = 0;
    while(a){
        LL tmp = a%d;
        a /= d;
        ans = ans*10 + tmp;
    }return ans;
}

int main(){
    LL n,d;
    prime();
    while(scanf("%lld", &n)!=EOF){
        if(n<0) break;
        scanf("%lld", &d);
        LL t = convert(n,d);
      //  printf("%lld\n",t);
        LL ans = 0;
        LL u = 1;
        while(t){
            LL tmp = t%10;
            t /= 10;
            ans = ans+tmp*u;
            u*=d;
        }
       // printf("%lld %lldxxxxxx\n", n,ans);
        if(!vis[n] && !vis[ans])
            puts("Yes");
            else puts("No");
    }return 0;
}
