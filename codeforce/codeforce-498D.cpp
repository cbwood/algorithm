/*************************************************************************
	> File Name: codeforce-498D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月17日 星期二 00时00分16秒
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

char s1[maxn], s2[maxn];
int a[30];

int main(){
    int n;
    scanf("%d", &n);
    scanf(" %s %s", s1+1,s2+1);

    int ans = 0;
    for(int i = 1; i <= n/2; ++i){
        for(int  j= 0; j <= 29; ++j) a[j] = 0;
        a[s1[i]-'a']++;
        a[s1[n-i+1]-'a']++;
        a[s2[i]-'a']++;
        a[s2[n-i+1]-'a']++;
        if(a[s1[i]-'a'] ==  1 && a[s1[n-i+1]-'a'] == 1 && a[s2[i]-'a'] == 1 && a[s2[n-i+1]-'a'] == 1)
            ans += 2;
        else if(a[s1[i]-'a'] ==  3 || a[s1[n-i+1]-'a'] == 3 || a[s2[i]-'a'] == 3 || a[s2[n-i+1]-'a'] == 3)
            ans += 1;
        else  if(a[s1[i]-'a'] ==  2 && (a[s1[n-i+1]-'a'] == 1 || a[s2[i]-'a'] == 1 || a[s2[n-i+1]-'a'] == 1))
            ans += 1;
        else  if((a[s1[i]-'a'] ==  1 || a[s1[n-i+1]-'a'] == 1 || a[s2[i]-'a'] == 1) && a[s2[n-i+1]-'a'] == 2)
            ans += 1;
        else  if(a[s1[n-i+1]-'a'] ==  2 && (a[s1[i]-'a'] == 1 || a[s2[i]-'a'] == 1 || a[s2[n-i+1]-'a'] == 1))
            ans += 1;
        else  if((a[s1[i]-'a'] ==  1 || a[s1[n-i+1]-'a'] == 1 || a[s2[n-i+1]-'a'] == 1 )&& a[s2[i]-'a'] == 2)
            ans += 1;
        printf("%d\n", ans);
    }if(n&1) if(s1[n/2+1] != s2[n/2+1]) ans++;
    printf("%d\n", ans);
	return 0;
}

