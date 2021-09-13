/*************************************************************************
	> File Name: cf182-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月23日 星期六 15时22分19秒
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
const int maxn = 1e6 + 10;

char s1[maxn], s2[maxn];
int nextt[maxn];

void getnext(char s[maxn]){
    int i = 1, j = 0, len = strlen(s+1);
    nextt[i] = 0;
    while(i <= len){
        if(j == 0 || s[i] == s[j]){
            ++j, ++i;
            nextt[i] = j;
        }else j = nextt[j];
    }
}

int main(){
    int a, b;
    scanf(" %s", s1+1);
    getnext(s1);
    int len1 = strlen(s1+1);
    a = len1 - nextt[len1+1] + 1;
    if(len1 % a == 0)
        len1 /= a;
    else a = len1;
    scanf(" %s", s2+1);
    memset(nextt, 0, sizeof(nextt));
    getnext(s2);
    int len2 = strlen(s2+1);
    b = len2 - nextt[len2+1] + 1;
    if(len2 % b == 0)
        len2 /= b;
    else b = len2;
    if(a != b){
        printf("0\n");
        return 0;
    }for(int i = 1; i <= a; ++i)
        if(s1[i] != s2[i]){
            printf("0\n");
            return 0;
        }
    int tmp = min(len1, len2);
    int ans = 0;
    for(int i = 1; i <= tmp; ++i)
        if(len1 % i == 0 && len2 % i == 0)
            ans++;
    printf("%d\n", ans);
	return 0;
}
