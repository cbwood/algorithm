/*************************************************************************
	> File Name: cf35-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月28日 星期四 22时45分07秒
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
    int a[10];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+ 3);
     if(a[0] == 1 || (a[0] == a[1] && a[1] == a[2] && a[1] == 3)){
        puts("YES");
        return 0;
    }if(a[0] == 2 && a[1] == 2){
        puts("YES");
        return 0;
    }puts("NO");
	return 0;
}
