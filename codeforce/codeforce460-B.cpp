/*************************************************************************
	> File Name: codeforce460-B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月31日 星期三 21时13分31秒
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
const int maxn = 1e9 + 10;

bool judge(int x){
    int sum = 0;
    while(x){
        sum += x%10;
        x /= 10;
    }return sum  == 10;
}

int main(){
    int k, ans, i;
    cin >> k;
    while(k){
        for( i = 10; i <= maxn; ++i){
            if(judge(i))
                k--;
            ans = i;
            if(!k) break;

    }}cout << ans << endl;
	return 0;
}
