/*************************************************************************
	> File Name: contest8-E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月04日 星期四 20时20分43秒
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
int n, k;
char s2[3][maxn];
bool flag;

void dfs(int t, int step){
    if(step > n) flag = true;
    if(flag) return;
    if(s2[t%2][step+1] != 'X')
        dfs(t, step+1);
    if(step-1 > 0 && s2[t%2][step-1] != 'X')
        dfs(t, step-1);
    if(s2[(t+1)%2][step+k] != 'X')
        dfs(t+1, step+k);
}

int main(){
    cin >> n >> k;
    scanf(" %s %s",s2[1]+1,s2[0]+1);
    flag = false;
    dfs(1, 1);
    if(flag)
        puts("YES");
    else puts("NO");
	return 0;
}
