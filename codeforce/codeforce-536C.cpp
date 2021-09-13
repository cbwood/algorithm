/*************************************************************************
	> File Name: codeforce-536C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月31日 星期四 20时54分44秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 +10;
struct ss{
	int x,y,id;
}a[maxn];
typedef long long LL;

bool cmp(const ss &p, const ss &q){
	return p.y < q.y;
}

int b[maxn], bb[maxn];

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i].x), a[i].id = i;
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i].y),b[i] = a[i].x, bb[i] = a[i].y;
	sort(a,a+n, cmp);
	int t = 0;
	while(m--){
		int xx,yy;
		long long ans = 0;
		scanf("%d%d", &xx, &yy);
		xx--;
		if(b[xx] == 0){
			for(;t< n; ++t){
				if(b[a[t].id] >= yy){
					b[a[t].id] -= yy;
					ans += 1LL*bb[a[t].id] * yy;
					yy = 0;
					break;
				}else {
					yy -= b[a[t].id];
					ans += 1LL*b[a[t].id]*bb[a[t].id];
					b[a[t].id] = 0;
				}
			}
		}else
		if(b[xx] <= yy){
			ans += 1LL*bb[xx] * b[xx];
			yy -= b[xx];
			b[xx] = 0;
			for(;t< n; ++t){
				if(b[a[t].id] >= yy){
					b[a[t].id] -= yy;
					ans += 1LL*bb[a[t].id] * yy;
					yy = 0;
					break;
				}else {
					ans += 1LL*b[a[t].id]*bb[a[t].id];
					yy -= b[a[t].id];
					b[a[t].id] = 0;
				}
			}
		}else {
			ans = 1LL*yy * bb[xx];
			b[xx] -= yy;
			yy = 0;
		}
		ans = (yy == 0) ? ans : 0;
		printf("%lld\n", ans);
	}return 0;
}
