/*************************************************************************
	> File Name: HDU-6296.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月25日 星期六 20时02分21秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int maxn = 1e3 + 10;
int sum[maxn][maxn];
vector<pair<pair<int,int >,pair<int, int>  > > v;

LL cal(LL x){
	return x*(x-1)*(x-2)/6;
}

LL solve(int dx, int dy){
	memset(sum, 0, sizeof sum);
	for(auto &x: v){
		sum[x.fi.fi+dx][x.fi.se+dy]++;
		sum[x.se.fi+1][x.fi.se+dy]--;
		sum[x.fi.fi+dx][x.se.se+1]--;
		sum[x.se.fi+1][x.se.se+1]++;
	}LL ans = 0;
	for(int i = 1; i <= 1000; ++i)
		for(int j = 1; j <= 1000; j++){
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
			ans += cal(sum[i][j]);
		}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		v.clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			int x,y,xx,yy;
			scanf("%d%d %d%d", &x,&y, &xx,&yy);
			v.pb(mp(mp(x,y),mp(xx,yy)));
		}printf("%lld\n", solve(0,0) - solve(0,1) - solve(1,0) + solve(1,1));
	}return 0;
}
