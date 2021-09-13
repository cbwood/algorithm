/*************************************************************************
	> File Name: codeforce-498A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月16日 星期一 22时25分28秒
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
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        if(!(x&1)) x--;
        printf("%d ", x);
    }
	return 0;
}
