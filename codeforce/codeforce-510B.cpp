/*************************************************************************
	> File Name: codeforce-510B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年09月17日 星期一 16时22分49秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
map<string, LL> q;
const LL inf = 1e16;
int main(){
	int n;
	LL x;
	string s;
	q["A"] = inf;
	q["B"] = inf;
	q["C"] = inf;
	q["AB"] = inf;
	q["AC"] = inf;
	q["BC"] = inf;
	q["ABC"] = inf;

	cin >> n;
	while(n--){
		cin >> x >> s;
		sort(s.begin(), s.end());
		q[s] = min(q[s], x);
	}
	LL ans = inf;
	ans = min(ans, q["ABC"]);
	ans = min(ans, q["AC"] + q["B"]);
	ans = min(ans, q["AB"]+ q["C"]);
	ans = min(ans, q["A"]+q["BC"]);
	ans = min(ans, q["A"] + q["B"] + q["C"]);
	ans = min(ans, q["AC"] + q["AB"]);
	ans = min(ans, q["AC"] + q["BC"]);
	ans = min(ans, q["AB"] + q["BC"]);
	if(ans == inf) ans = -1;
	cout << ans << endl;
	return 0;
}
