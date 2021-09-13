#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000;

int bits[maxn];

int main(){
    int n,b;
    scanf("%d %d", &n, &b);
    int k = 0;
    while(n){
        bits[++k] = n%b;
        n /= b;
    }
    bool flag = true;
    for(int i = 1; i <= k/2; ++i)
        if(bits[i] != bits[k-i+1])
            flag = false;
    if(flag)
        puts("Yes");
    else puts("No");
        for(int i = k; i > 1; --i)
            printf("%d ",bits[i]);
        printf("%d\n",bits[1]);
    return 0;
}
