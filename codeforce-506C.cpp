/*************************************************************************
	> File Name: codeforce-506C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月24日 星期五 23时23分32秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v;

int main(){
	int n;
	scanf("%d", &n);
	int l1 = -1,l2 = -1, r1 = 1e9+1,r2 = 1e9+1;
	for(int i = 0; i < n; ++i){
		int x,y;scanf("%d%d", &x, &y);
		int tx=x,ty=y;
		if(l1 < x) swap(l1,x);
		if(l2 < x) swap(l2,x);
		if(r1 > y) swap(r1,y);
		if(r2 > y) swap(r2,y);
		v.push_back(make_pair(tx,ty));
	}int ans = 0;
	int xx,yy;
	for(auto &x: v){
		if(x.first == l1) xx = l2;
		else xx = l1;
		if(x.second == r1) yy = r2;
		else yy = r1;
		ans = max(ans, max(0,yy-xx));
	}printf("%d\n",ans);
}
