/*************************************************************************
	> File Name: LightOj1010.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月29日 星期日 15时45分00秒
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
int main(){
    int t, n, m, kase  = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d",&n, &m);
        int ans = n  / 2  * m;
        if(n&1) ans += (m + 1) / 2;
        if(m == 1) ans = n;
        if(n == 1) ans = m;
        if(m == 2) ans = (n / 4 * 4 + (n % 4 > 2 ? 2 : n % 4) * 2);
        if(n == 2) ans = (m / 4 * 4 + (m % 4 > 2 ? 2 : m % 4) * 2);
        printf("Case %d: %d\n", ++kase, ans);
    }
	return 0;
}
