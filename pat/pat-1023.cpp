#include<bits/stdc++.h>
using namespace std;

int num1[10], num2[10];
char s[100];
int ans[100];

int main(){
    scanf("%s", s);
    int len = strlen(s);
    int x = 0;
    int id = 0;
    for(int i = len-1; i >= 0; --i){
        int k = s[i]-'0';
        num1[k]++;
        int a = k*2+x;
        x = a/10;
        a %= 10;
        num2[a]++;
        ans[id++] = a;
    }if(x){
        ans[id++] = x;
        num2[x]++;
    }
    bool flag = true;
    for(int i = 0; i < 10; ++i)
        if(num1[i] != num2[i])
            flag = false;
    if(flag) puts("Yes");
    else puts("No");
    for(int i = id-1; i >= 0; --i)
        printf("%d", ans[i]);
    return 0;
}
