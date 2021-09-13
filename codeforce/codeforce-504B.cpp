/*************************************************************************
	> File Name: codeforce-504B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月17日 星期五 22时48分16秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2e5 + 10;

char s[maxn];

int main(){
	LL n,k;
	cin >> n >> k;
	LL ans = 0;
	if(n >= k){
		ans = k/2;
		if(k%2 == 0) ans--;
	}
	else {
		ans = max(0LL, n-k/2);
	}cout << ans << endl;
	return 0;
}
