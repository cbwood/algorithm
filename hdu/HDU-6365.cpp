/*************************************************************************
	> File Name: HDU-6365.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月10日 星期五 11时28分27秒
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
const LL mod = 1e9 + 7;
const int maxn = 6e2 + 10;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

vector<pair<pair<int,int> ,int> > vec;
int pl[maxn],pr[maxn];
int l[maxn],r[maxn];
vector<int> v;
LL dp[maxn][maxn];
int w[maxn][maxn];
int n;


struct ss{
    int H, L, R, W;
    bool operator <(const ss &rhs)const{
        return W > rhs.W;
    }
}a[maxn];

bool cmp(const pair<pair<int,int>, int> &a,const pair<pair<int,int> ,int> &b){
    return (1LL*a.fi.fi * b.fi.se < 1LL*a.fi.se * b.fi.fi);
}

LL solve(){
    int sz = v.size();
    memset(w, -1, sizeof w);
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < l[i]; ++j)
            for(int k = sz+1; k > r[i]; --k)
                if(w[j][k] == -1) w[j][k] = i;
    for(int k = 0; k <= sz+1; ++k)
        for(int i = 0; i + k <= sz+1; ++i){
         int j = i + k;
            dp[i][j] = 1LL<<60;
            int t = w[i][j];
            if(t == -1){
                dp[i][j] = 0;
                continue;
            }for(int x = l[t]; x <= r[t]; ++x)
                dp[i][j] = min(dp[i][j], dp[i][x] + dp[x][j] + a[t].W);
     }return dp[0][sz+1];
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d%d%d%d", &a[i].H, &a[i].L, &a[i].R, &a[i].W);
        sort(a+1,a+1+n);vec.clear();
        for(int i = 1; i <= n; ++i){
            vec.pb(mp(mp(a[i].L,a[i].H), i));
            vec.pb(mp(mp(a[i].R,a[i].H), i));
            pl[i] = pr[i] = -1;
        }sort(vec.begin(),vec.end(), cmp);
        int t = 0;
        for(int i = 0; i < 2*n; ++i){
            if(i && cmp(vec[i-1], vec[i])== 1) t++;
            if(pl[vec[i].se] == -1) pl[vec[i].se] = 2*t;
            else pr[vec[i].se] = 2*t+1;
        }v.clear();
        for(int i = 1; i <= n; ++i)
            v.pb(pr[i]);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()), v.end());
        for(int i = 1; i <= n; ++i){
            l[i] = lower_bound(v.begin(),v.end(),pl[i]) - v.begin()+1;
            r[i] = lower_bound(v.begin(),v.end(),pr[i]) - v.begin()+1;
        }
        printf("%lld\n", solve());
    }
	return 0;
}
