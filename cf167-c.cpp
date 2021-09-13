/*************************************************************************
	> File Name: cf167-c.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月21日 星期四 18时20分07秒
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

int SG(LL a, LL b){
    if(a == 0 || b == 0)
        return 0;
    if(SG(b % a, a)){
        b /= a;
        return !(b % (a + 1)&1);
    }return 1;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        LL a, b;
        cin >> a >> b;
        int num = 1;
        if(a > b) swap(a, b);
        if(SG(a, b) == 0)
            cout << "Second" << endl;
        else cout << "First" << endl;
    }
	return 0;
}
