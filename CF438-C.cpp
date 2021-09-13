/*************************************************************************
	> File Name: CF438-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月05日 星期四 15时45分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define sqr(x) ((x)*(x))
using namespace std;

typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

set<int> q;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int t, x;
    q.clear();
    bool check = false;
    while(n--){
        x = 0;
        int kk = k;
        while(kk--){
            cin >> t;
            x = x * 2 + t;
        }
        if(x == 0)
            check = true;
        for(auto tt : q)
            if((tt & x) == 0)
                check = true;
        q.insert(x);
    }
    if(check)
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
