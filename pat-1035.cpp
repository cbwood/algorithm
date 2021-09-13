#include<bits/stdc++.h>
using namespace std;

struct ss{
    char nam[20],pwd[20];
}ans[1002];

int main(){
    int n,m=0;
    scanf("%d", &n);
    for(int i = 0;i < n; ++i){
        char pw[20];
        scanf("%s %s", ans[m].nam, pw);
        bool check = false;
        int len = strlen(pw);
        for(int j = 0; j < len; ++j){
            if(pw[j] == '1'){
                check = true;
                pw[j] = '@';
            }
            if(pw[j] == '0'){
                check = true;
                pw[j] = '%';
            }
            if(pw[j] == 'l'){
                check = true;
                pw[j] = 'L';
            }
            if(pw[j] == 'O'){
                check = true;
                pw[j] = 'o';
            }
        }
        if(check){
            strcpy(ans[m].pwd, pw);
            m++;
        }
    }if(m == 0){
        if(n == 1)
            printf("There is 1 account and no account is modified\n");
        else printf("There are %d accounts and no account is modified\n", n);
    }else{
        printf("%d\n",m);
        for(int i = 0; i < m; ++i)
            printf("%s %s\n", ans[i].nam, ans[i].pwd);
    }
    return 0;
}