#include<bits/stdc++.h>
using namespace std;

void tans(int n){
    map<int, char> mp;
    mp[10] = 'A';
    mp[11] = 'B';
    mp[12] = 'C';
    char s[10];
    int k = 0;
    while(n){
        int tmp=n%13;
        n /= 13;
        if(tmp >= 10)
            s[k++] = mp[tmp];
        else s[k++] = tmp+'0';
    } k--;
    while(k < 1)
        s[++k] = '0';
    for(int i = k; i >= 0; --i){
        printf("%c",s[i]);
    }
}

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    printf("#");
    tans(a);
    tans(b);
    tans(c);
    return 0;
}
