/*************************************************************************
	> File Name: POJ-2926.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月22日 星期三 18时59分16秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const double INF = 1e18;

const int d = 5;
double a[d];
double maxi[1<<d],mini[1<<d];

void init(){
	for(int i = 0; i < 1<<d; ++i)
		mini[i] = INF, maxi[i] = -INF;
}

void update(){
	for(int i = 0; i < 1<<d; ++i){
		double now = 0;
		for(int j = 0; j < d; ++j)
			if(i&(1<<j)){
				now += a[j];
			}else now -= a[j];
		maxi[i] = max(maxi[i], now);
		mini[i] = min(mini[i], now);
	}
}

int  main(){
	int n;
	while(scanf("%d", &n) != EOF){
		init();
		while(n--){
			for(int i = 0; i < d; ++i)
				scanf("%lf", &a[i]);
			update();
		}double ans = 0;
		for(int i = 0; i < 1 << d; ++i)
			ans = max(maxi[i]-mini[i], ans);
		printf("%.2f\n", ans);
	}
}
