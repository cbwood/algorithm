/*************************************************************************
	> File Name: HDU-4821.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年09月26日 星期三 21时22分09秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
char s[maxn];

typedef unsigned long long ull;


map<ull, int> mp;
ull Hash[maxn], nbase[maxn];

int main(){
	int m,l;
	ull base = 11;
	nbase[0] = 1;
	for(int i = 1; i < maxn; ++i) nbase[i] = nbase[i-1] * base;
	while(scanf("%d%d", &m, &l) != EOF){
		scanf(" %s", s);
		int len = strlen(s);
		Hash[len] = 0;
		int ans = 0;
		for(int i = len-1; i >= 0; --i)
			Hash[i] = Hash[i+1] * base + s[i] - 'a'+1;
		for(int i = 0; i < l && i + m*l <= len; ++i){
			mp.clear();
			for(int j = i; j < i + m*l; j += l){
				ull tmp = Hash[j] - Hash[j+l] * nbase[l];
				mp[tmp]++;
			}if(mp.size() == m) ans++;
			for(int j = i+m*l; j + l <= len; j += l){
				ull tmp = Hash[j-m*l] - Hash[j-(m-1)*l]*nbase[l];
				mp[tmp]--;
				if(mp[tmp] == 0) mp.erase(tmp);
				tmp = Hash[j] - Hash[j+l]*nbase[l];
				mp[tmp]++;
				if(mp.size() == m) ans++;
			}
		}printf("%d\n", ans);
	}return 0;
}
