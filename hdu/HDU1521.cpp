/*************************************************************************
	> File Name: HDU1521.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月02日 星期五 09时45分21秒
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

double f(int n){
    double ans = 1;
    for(int i = 1;i <= n; ++i)
        ans = ans * i;
    return ans;
}

double a[15], b[15];
int num[15];

int main(){
    int n, m;
        while(cin >> n >> m){
        for(int i = 1; i <= n; ++i)
            cin >> num[i];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i <= num[1]; ++i)
            a[i] = 1.0 / f(i);
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j <= m; ++j)
                for(int k = 0; j + k <= m && k <= num[i]; ++k)
                    b[j+k] += a[j] / f(k);
            for(int j = 0; j <= m; ++j)
                a[j] = b[j], b[j] = 0;
        }printf("%.0f\n", a[m] * f(m));
    }
	return 0;
}
