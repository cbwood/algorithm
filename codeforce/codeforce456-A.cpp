/*************************************************************************
	> File Name: codeforce456-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月05日 星期五 22时20分55秒
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

LL max(LL a, LL b){
    return a > b ? a : b;
}

int main(){
    LL a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    LL a1 = 2*x + y, a2 = y + 3 * z, ans = 0;
    ans = max(0, a1-a) + max(0, a2-b);
    cout << ans << endl;
	return 0;
}
