#include<bits/stdc++.h>
using namespace std;

map<int, char*> m;
int main(){
    m[0] = "zero";
    m[1]= "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "seven";
    m[8] = "eight";
    m[9] = "nine";
    m[10] = "ten";
    char s[1002];
    scanf(" %s", s);
    int len = strlen(s);
    int ans = 0;
    for(int i = 0; i < len; ++i)
        ans += s[i] - '0';
    int a[1002];
    int k = 0;
    while(ans){
        a[++k] = ans%10;
        ans /= 10;
    }printf("%s",m[a[k]]);
    for(int i = k-1; i >= 1; --i)
        printf(" %s",m[a[i]]);
    return 0;
}
