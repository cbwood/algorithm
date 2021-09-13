/*************************************************************************
	> File Name: codeforce456-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月05日 星期五 23时18分41秒
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

int a[maxn];

LL min(LL a, LL b){
    return a > b ? b : a;
}

LL max(LL a, LL b){
    return a > b ? a: b;
}

int main(){
    for(int i = 0; i < maxn; ++i){
        a[i] = i + 1;
        if(i&1) a[i] = -a[i];
    }
    LL  n, m, r, k;
    cin >> n >> m >> r >> k;
    LL num = 0;
    if(k > m*(n-1)){
        num = (m - r + 1) * r;
    }
    int nn = (n +1)/ 2 ,t = 0;
    while(k){
        LL tmp;
        if(k >= m){
            tmp = m;
            k -= m;
            if(nn > r)
                num += (m - r + 1) *(min(n - nn + 1, r)) * r;
            else num += (m - r + 1) * (min(n - r +1, nn)+0) * r;
        }else{
            break;
            tmp = k, k = 0;
            if(tmp <= r){
                LL t = max(1LL, tmp - (m -r));
                if(nn > r) tmp = (tmp+1-t) * (tmp + t) / 2 * min(n -nn +1, r);
                else tmp = (tmp +1-t) *(tmp + t) / 2 * min(n-r+1, nn);
                num += tmp;
            }else {
                int x = tmp - r;
                if(nn > r)
                    num += (m - r + 1) * min(n - nn + 1, r) * (tmp - r);
                else num += (m - r + 1) * min(n - r +1, nn) * (tmp - r);
                tmp = r;
                m = m - x;
                LL t = max(1LL, tmp - (m-r));
                if(nn > r) tmp = (tmp +1-t)* (tmp + t) / 2 * min(n -nn +1, r);
                    else tmp = (tmp+1-t) *(tmp + t) / 2 * min(n-r+1, nn);
                num += tmp;
            }
        }nn += a[t++];
    }
    int kk = nn;
    nn = (m + 1) / 2;
    t = 0;
    while(k){
        if(nn > r && kk > r)
            num += (nn-r + min(m -nn+1,r)) * (kk - r + min(n -kk+1, r));
        else if(nn > r && kk <= r)
            num += (nn - r + min(m-nn+1, r)) * (min(kk, n - r + 1));
        else if(kk > r)
            num += min(nn, m - r+1) * (kk-r+min(n-kk+1, r));
        else num += min(nn, m - r + 1) * (kk, n - r + 1);
        k--;
        nn += a[t++];
    }
    printf("%.10f\n", num * 1.0 / ((n-r+1)*(m-r+1)));
	return 0;
}
