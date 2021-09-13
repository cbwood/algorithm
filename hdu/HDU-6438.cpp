/*************************************************************************
	> File Name: HDU-6438.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月25日 星期六 20时47分48秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define mp make_pair
#define se second
#define fi first

multiset<pair<LL,int> > s;


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		s.clear();
		int n;
		scanf("%d", &n);
		LL x;
		LL a1=0,a2=0;
		while(n--){
			scanf("%lld", &x);
			if(s.empty()) s.insert(mp(x,1));
			else if(s.begin()->fi < x){
				a1 += x-s.begin()->fi;
				a2 += s.begin()->se;
				pair<LL,int> tmp = *s.begin();
				s.erase(s.begin());
				if(tmp.se == 0) s.insert(mp(tmp.fi,1));
				s.insert(mp(x,0));
			}else s.insert(mp(x,1));
		}printf("%lld %lld\n",a1,a2*2);
	}
	return 0;
}
