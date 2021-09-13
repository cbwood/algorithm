#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    int k = (len+2)/3;
    int xk = len-k*2;
    for(int i = 0; i < k; ++i){
        printf("%c",s[i]);
        if(i != k-1)
            for(int j = 0; j < xk; ++j)
                printf(" ");
        else for(int j = k; j < xk+k; ++j)
                printf("%c", s[j]);
        printf("%c\n",s[len-i-1]);
    }
    return 0;
}