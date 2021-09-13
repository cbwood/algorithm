/*************************************************************************
	> File Name: contest7-G.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年11月19日 星期日 18时45分38秒
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
    int a, b;
    while(scanf("%d:%d", &a, &b) != EOF){
        if(a >= 12 || b >= 60 || a * b < 0){
            puts("That is a joke.");
            continue;
        }a = 11 - a;
        b = 60 - b;
        if(b == 60){
            b = 0;
            a++;
        }
        printf("%02d:%02d\n", a, b);
    }
	return 0;
}
