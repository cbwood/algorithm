/*************************************************************************
	> File Name: GoodBye2017-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月29日 星期五 23时51分11秒
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

map<char, bool> q;

int main(){
    string s;
    cin >> s;
    int len = s.length();
    int ans = 0;
    q['a'] = q['e'] = q['i'] = q['u'] = q['o'] = 1;
    q['0'] = q['2'] = q['4'] = q['6'] = q['8'] = 1;
    for(int i = 0; i < len; ++i){
        if(s[i] >= 'a' && s[i] <= 'z' && q[s[i]])
            ans++;
        else if(s[i] >= '0' && s[i] <= '9' && !q[s[i]])
            ans++;
    }cout << ans << endl;
	return 0;
}
