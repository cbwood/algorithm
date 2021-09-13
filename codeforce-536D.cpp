/*************************************************************************
	> File Name: codeforce-536D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月31日 星期四 21时33分52秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

set<int> s;
const int maxn = 1e5+10;
vector<int> a[maxn];
bool vis[maxn];

int main(){
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++ i){
		int x,y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	printf("1");
	vis[1] = 1;
	for(auto x : a[1])
		if(!vis[x])
		s.insert(x), vis[x] = 1;
	while(!s.empty()){
		int k = *s.begin();
		printf(" %d", k);
		s.erase(k);
		for(auto x : a[k])
			if(!vis[x])
				s.insert(x),vis[x] = 1;
	}return 0;
}
