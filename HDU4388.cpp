/*************************************************************************
	> File Name: HDU4388.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月03日 星期二 12时49分18秒
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

int solve(int n){
    int sum = 0;
    while(n){
        sum += n&1;
        n /= 2;
    }return sum;
}

int main(){

    int t, kase = 0;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            int x;
            cin >> x;
            sum += solve(x);
        }
        printf("Case %d: ", ++kase);
        sum += n;
        puts(sum&1 ? "Yes" : "No");
    }
	return 0;
}
