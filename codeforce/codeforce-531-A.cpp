/*************************************************************************
	> File Name: codeforce-531-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月09日 星期三 22时29分57秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	int ans;
	if(n%4 == 0||n%4 == 3) ans = 0;
	if(n%4 == 1 || n%4 == 2) ans = 1;
	cout << ans << endl;
	return 0;
}
