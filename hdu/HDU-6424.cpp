/*************************************************************************
	> File Name: HDU-6424.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月23日 星期四 14时46分51秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int INF = 2e9;

struct ss{
	int x,y;
	ss(int _x, int _y){
		x=_x;y=_y;
		if(x > y) swap(x,y);
	};
};

int cmp(const ss &a, const ss &b){
	if(a.x < b.x) return 1;else if(a.x > b.x) return -1;
	if(a.y < b.y) return 1;else if(a.y > b.y) return -1;
	return 0;
}

int solve(ss a1, ss a2, ss b1, ss b2){
	if(cmp(a1,a2) < 0) swap(a1,a2);
	if(cmp(b1,b2) < 0) swap(b1,b2);

	if(cmp(a1,b1)) return cmp(a1,b1);
	return cmp(a2,b2);
}

int A[4],B[4];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a,b;
		scanf("%d%d", &a, &b);
		for(int i = 1; i <= 3; ++i)
			A[i] = B[i] = INF;
		for(int i = 1; i <= a; ++i)
			scanf("%d",A+i);
		for(int i = 1; i <= b; ++i)
			scanf("%d",B+i);
		ss a1 = ss(A[1]+2,INF), a2 = ss(A[3],A[2]+1);
		ss b1 = ss(B[1]+2,INF), b2 = ss(B[3],B[2]+1);
		printf("%d\n", solve(a1,a2,b1,b2));
	}return 0;
}

