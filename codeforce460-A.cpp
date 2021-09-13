/*************************************************************************
	> File Name: codeforce460-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月31日 星期三 21时06分01秒
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

int main(){
    int n, m;
    cin >> n >> m;
    double ans = 1e9;
    while(n--){
        double x, y;
        cin >> x >> y;
        ans = min(ans,x/y);
    }printf("%.9f\n", ans*m);
	return 0;
}
