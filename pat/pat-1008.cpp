#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int sum = 0;
    int pre = 0;
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        if(x > pre){
            sum  = sum+5+6*(x-pre);
        }else sum =sum+5+4*(pre-x);
        pre = x;
    }
    printf("%d", sum);
    return 0;
}
