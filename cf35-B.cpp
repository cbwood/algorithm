/*************************************************************************
	> File Name: cf35-B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月28日 星期四 22时13分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<string>

using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int n, a, b;

bool solve(int x){
    if(a / x + b / x >= n)
        return false;
    return true;
}

int main(){
    cin >> n >> a >> b;
    int l = 1, r = a + b;
    int ans = 1;
    for(int  i = 1; i <= r; ++i)
        if(a / i + b / i >= n && a /i && b / i)
            ans = i;
    cout << ans << endl;
	return 0;
}
