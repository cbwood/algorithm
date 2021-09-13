/*************************************************************************
	> File Name: codeforce-536B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月31日 星期四 20时48分18秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
typedef long long LL;
LL a[maxn];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a,a+n);
	LL ans = 0;
	for(int i = 0; i < n/2; ++i)
		ans += (a[i] + a[n-i-1])*(a[i]+a[n-i-1]);
	cout << ans << endl;
}
