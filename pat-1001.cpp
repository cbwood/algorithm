#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int d[maxn];

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    int sum = abs(a+b);
    int k = 0;
    while(sum){
        d[++k] = sum%10;
        sum /= 10;
    }
    if(k <= 3){
        printf("%d\n", a+b);
        return 0;
    }
    if(a+b<0) printf("-");
    printf("%d",d[k--]);
    while(k){
        if(k%3 == 0)
            printf(",");
        printf("%d",d[k--]);
    }printf("\n");
    return 0;
}

