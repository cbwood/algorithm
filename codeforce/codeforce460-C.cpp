/*************************************************************************
	> File Name: codeforce460-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月31日 星期三 22时06分32秒
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
const int maxn = 2000 + 10;

char w[maxn][maxn];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        scanf(" %s", w[i] + 1);
    LL ans = 0;
    for(int i = 1; i <= n; ++i){
        int num = 0;
        for(int j = 1; j <= m; ++j)
            if(w[i][j] == '.')
                num++;
        else {
            if(num >= k)
             ans += num - k + 1;
            num = 0;
        }
        if(num >= k)
            ans += num - k + 1;
    }
     for(int i = 1; i <= m; ++i){
        int num = 0;
        for(int j = 1; j <= n; ++j)
            if(w[j][i] == '.')
                num++;
        else {
            if(num >= k)
             ans += num - k + 1;
            num = 0;
        }
        if(num >= k)
            ans += num - k + 1;
    }
    if(k == 1) ans /= 2;
    cout << ans << endl;
	return 0;
}
