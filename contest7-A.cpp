/*************************************************************************
	> File Name: contest7-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月02日 星期二 19时45分04秒
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
#include<vector>
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

vector <pair<int,int>> a;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int n;
    ios::sync_with_stdio(0);
    cin >> n;
    while(n--){
        int k, b;
        cin >> k >> b;
        if(k != 0){
            if(k < 0){
                k = - k;
                b = - b;
            }int g = gcd(k, b);
            k /= g, b/= g;
            a.push_back(make_pair(k,b));
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << a.size() << endl;
	return 0;
}
