/*************************************************************************
	> File Name: HDU1525.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年03月24日 星期六 09时58分14秒
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
    while(scanf("%d %d", &n, &m) != EOF &&(n||m)){
        if(n < m)
            swap(n, m);
        int num = 0;
        while(m){
            if(n > 2*m || n % m == 0)
                break;
            num ^= 1;
            n = n - m;
            swap(n, m);
        }
        if(num)
            puts("Ollie wins");
        else puts("Stan wins");
    }
	return 0;
}
