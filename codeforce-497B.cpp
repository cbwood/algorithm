/*************************************************************************
	> File Name: codeforce-497B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月13日 星期五 22时47分16秒
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
    cin >> n;
    int mini = 1e9+1;
    bool check = true;
    for(int i = 0; i < n; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        int mx = max(x, y);
        int my = min(x, y);
        if(mini >= mx)
            mini = mx;
        else if(mini >= my)
            mini = my;
        else check = false;
    }
    if(check) puts("YES");
    else puts("NO");
	return 0;
}
