/*************************************************************************
	> File Name: POJ-2443.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月23日 星期四 20时12分58秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;

bitset<1009> bit[maxn];

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < maxn; ++i)
			bit[i].reset();
		for(int i = 1, m,x; i <= n; ++i){
			scanf("%d", &m);
			while(m--){
				scanf("%d", &x);
				bit[x].set(i);
			}
		}int q;
		scanf("%d" ,&q);
		while(q--){
			int x,y;
			scanf("%d%d", &x, &y);
				bitset<1009> ans = bit[x]&bit[y];
			if(ans.count()) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
