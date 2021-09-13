/*************************************************************************
	> File Name: codeforce-506F.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月27日 星期一 17时41分42秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define pb  push_back

vector<int> vec;


LL solve(LL a, LL b){
	LL c = a+b;
	vec.clear();
	for(LL i = 1; i * i <= b; ++i)
		if(b % i == 0)
			vec.pb(i);
	int t = 0;
	LL ans = 2 *(a+b)+2;
	int sz = vec.size();
	for(LL i = 1; i * i <= c; ++i)
		if(c % i == 0){
			while(t+1 < sz && vec[t+1] <= i)
				++t;
			if(b/vec[t] <= c/i)
				ans = min(ans, 2LL*(i + c/i));
		}
	return ans;
}

int main(){
	LL a,b;
	cin >> a >> b;
	cout << min(solve(a,b), solve(b,a))<<endl;
}
