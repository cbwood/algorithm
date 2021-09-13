/*************************************************************************
	> File Name: cccc.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年03月20日 星期二 13时12分22秒
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
const int maxn = 5e5 + 10;
const int INF = 0x3f3f3f3f;

map<int, int> q;
int a[maxn];

int main(){
    int n;
    scanf("%d", &n);
    int k = 0;
    int nn = n;
    while(n--){
        int m;
        scanf("%d", &m);
        while(m--){
            int x;
            scanf("%d", &x);
            if(q[x] == 0)
                q[x] = ++k;
            a[q[x]]++;
        }
    }
    int num1 = 0, num2 = 0;
    for(int i = 1; i <= k; ++i){
        if(a[i] == 1)
            num1++;
        if(a[i])
            num2++;
    }printf("%.2f",100.0*num1/num2);
    putchar('%');
    return 0;
}
