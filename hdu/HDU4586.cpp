/*************************************************************************
	> File Name: HDU4586.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月16日 星期一 15时32分16秒
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
    int n;
    while(scanf("%d", &n) != EOF){
        double sum = 0;
        for(int i = 1; i <= n; ++i){
            double x;
            scanf("%lf", &x);
            sum += x;
        }int m;
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i){
            int x;
            scanf("%d", &x);
        }if(sum == 0) puts("0.00");
        else if(n == m)
            puts("inf");
        else printf("%.2f\n", sum/(n-m));
    }
	return 0;
}
