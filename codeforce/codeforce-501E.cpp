/*************************************************************************
	> File Name: codeforce-501E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月27日 星期五 20时49分54秒
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
#define sqr(x) (x)*(x)
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int a[maxn];
int b[maxn];
int used[maxn];

int main(){
    int n;
    scanf("%d", &n);

    int k = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d",&a[i]);
        b[a[i]]++;
        if(b[a[i]]&1) k++;
        else k--;
    }if(k > 1) { printf("0\n"); return 0;}
    LL pos = 0;
    for(int i = 1; i <= n/2; ++i)
        if(a[i] != a[n-i+1]){
            pos = i;
            break;
        }else b[a[i]] -= 2;
    if(!pos){
        printf("%lld\n", 1LL*n*(n+1)/2);
        return 0; 
    }
    int len = 0;
    for(int i = pos; i <= n; ++i){
        used[a[i]]++;
        if(used[a[i]]*2 > b[a[i]]){
            if(i < n-i+1 ||(i == n-i+1 && b[a[i]]%2 == 0) || a[i] != a[n-i+1]) break;
        }len++;
    }memset(used, 0, sizeof used);
    for(int i = n-pos+1; i >= 1; --i){
        used[a[i]]++;
        if(used[a[i]]*2 > b[a[i]])
            if(i > n-i+1 || (i == n-i+1 && b[a[i]]%2 == 0) || a[i] != a[n-i+1]) break;
        len++;
    }printf("%lld\n", pos*(pos+len));
	return 0;
}
