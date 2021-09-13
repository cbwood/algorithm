#include<bits/stdc++.h>
using namespace std;

int a[10000], k, b[10000], len;
char s[10000];

void convert(){
    for(int i = 0; i <= len; ++i)
        b[i] = a[len-i];
}

bool check(){
    for(int i = 0; i <= len; ++i)
        if(a[i] != b[i]) return 0;
    return 1;
}

void dfs(int step){
    convert();
    if(step == k || check()){
        for(int i = len; i >= 0; --i)
            printf("%d",a[i]);
        printf("\n%d\n", step);
        return ;
    }int x = 0;
    for(int i = 0; i <= len; ++i){
        a[i] = a[i]+b[i]+x;
        x = a[i]/10;
        a[i] %= 10;
    }if(x) a[++len] = x;
    dfs(step+1);
}

int main(){
    scanf("%s %d", &s, &k);
    len = strlen(s)-1;
    for(int i = len; i >= 0; --i)
        a[len-i] = s[i]-'0';
    dfs(0);
    return 0;
}
