/*************************************************************************
	> File Name: codeforce-497A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月13日 星期五 22时18分27秒
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

char s[maxn];

bool check(char s){
    if(s == 'a' || s == 'e' || s == 'o' || s== 'i' || s == 'u')
        return true;
    return false;
}

int main(){
    scanf(" %s", s);
    int len = strlen(s);
    bool checks = true;
    for(int i = 0; i < len; ++i){
        if(!check(s[i]) && s[i] != 'n')
            if(!check(s[i+1]))
                checks = false;
    }if(checks) puts("YES");
    else puts("NO");
	return 0;
}
