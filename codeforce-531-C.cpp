/*************************************************************************
	> File Name: codeforce-531-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月09日 星期三 23时13分13秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x,y;
	cin >> n >> x >> y;
	int num = 0;
	int k;
	for(int i = 0; i < n; ++i){
		cin >> k;
		if(k <= x) num++;
	}int ans = 0;
	if(x <= y)
		ans = (num+1)/2;
	else ans = n;
	cout << ans << endl;
}
