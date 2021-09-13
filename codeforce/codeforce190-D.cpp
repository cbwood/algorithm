/*************************************************************************
	> File Name: codeforce190-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月01日 星期一 17时40分56秒
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
const int maxn = 4e5 + 10;

map<int , int > q;
int a[maxn];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 1, r = 1, flag = 0;
    while(!flag && r <= n){
        q[a[r]]++;
        if(q[a[r]] == k)
            flag = 1;
        else r++;
    }
    LL ans = 0;
    while(r <= n && flag){
        ans += n - r + 1;
        if(q[a[l]] == k){
            flag = 0;
            r++;
        }q[a[l]]--;
        l++;
        while(!flag && r <= n){
            q[a[r]]++;
            if(q[a[r]] == k)
                flag = 1;
            else r++;
        }
    }cout << ans << endl;
	return 0;
}
