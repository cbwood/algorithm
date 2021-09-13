/*************************************************************************
	> File Name: HDU4559.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月03日 星期二 16时23分16秒
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
const int maxn = 5e3 + 10;

bool vis[3][maxn];

bool judge(int i){
    if(vis[1][i] || vis[2][i] || vis[1][i+1] || vis[2][i+1])
        return false;
    return true;
}

int main(){
    int t, kase = 0;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= m; ++i){
            int x, y;
            cin >> x >> y;
            vis[x][y] = 1;
        }
        int sum = n * 2;
        int num4 = 0;
        for(int i = 1; i < n; ++i)
            if(judge(i)){
                i++;
                num4++;
            }
        printf("Case %d: ", ++kase);
        int num1 = sum - m - num4*4;
        if(num1&1){
            puts(num4 >= 1 ? "Bob" : "Alice");
        }else puts(num4 >= 1 ? "Alice" : "Bob");
    }
	return 0;
}
