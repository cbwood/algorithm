/*************************************************************************
	> File Name: codeforce189-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月01日 星期一 16时03分47秒
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
const int maxn = 1e6 + 10;

int f[maxn], a[maxn];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        f[x] = i;
    }for(int i = 1; i <= n; ++i){
        a[i] = f[a[i]];
    }for(int i = 1; i < n; ++i)
    if(a[i] > a[i+1]){
        cout << n - i << endl;
        return 0;
    } cout<< 0 << endl;
	return 0;
}
