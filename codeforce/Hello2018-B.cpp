/*************************************************************************
	> File Name: Hello2018-B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月08日 星期一 22时58分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>

using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e3 + 10;

vector<int> q[maxn];
bool flag, vis[maxn];

int  dfs(int u){
    vis[u] = true;
    if(q[u].size() == 0) return 1;
    if(flag) return 0;
    int num = 0;
    for(int i = 0; i < q[u].size(); ++i){
        if(!vis[q[u][i]])
        num += dfs(q[u][i]);
    }if(num < 3) flag = true;
    return 0;
}

int main(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; ++i){
        int x;
        cin >>  x;
        q[x].push_back(i);
    }int num = 0;
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    if(!flag)
        cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
