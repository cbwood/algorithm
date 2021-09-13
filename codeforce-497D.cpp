/*************************************************************************
	> File Name: codeforce-497D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月13日 星期五 23时43分13秒
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

int geta(int n){
    int m = sqrt(n+0.5);
    int ans = 0;
    for(int i = 1; i <= m; ++i)
        if(n % i == 0){
            ans += 2;
            if(i*i == n) ans--;
    }return ans;
}

int getab(int a, int b){
    int ans = 0;
    for(int i = 1; i <= min(a,b); ++i)
        if(a%i == 0 && b % i == 0)
            ans++;
    return ans;
}

int get(int a, int b, int c){
    int up = min(a, min(b,c));
    int ans = 0;
    for(int i = 1; i <= up; ++i)
        if(a%i ==0 &&b %i == 0 && c %i == 0)
            ans++;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        LL ans = 1LL*geta(a)*geta(b)*geta(c);
        ans = ans - 1LL*getab(a,b)*geta(c) - 1LL*getab(a,c)*geta(b) - 1LL*geta(a)*getab(b,c);
        ans += get(a,b,c);
        cout << ans << endl;
    }
	return 0;
}
