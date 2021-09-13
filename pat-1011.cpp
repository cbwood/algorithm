#include<bits/stdc++.h>
using namespace std;

double w[4][4];
char s[4],anss[4];
double ans = 1;

void dfs(double t, int k){
    if(k == 4){
        if(t > ans){
            ans = t;
            anss[1] = s[1];
            anss[2] = s[2];
            anss[3] = s[3];
        }return ;
    }
    for(int i = 0; i < 3; ++i){
        if(i == 0)
            s[k] = 'W';
        else if(i == 1)
            s[k] = 'T';
        else s[k] = 'L';
        dfs(t*w[k-1][i], k+1);
    }
}

int main(){
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            scanf("%lf", &w[i][j]);
    dfs(1.0, 1);
    printf("%c %c %c %.2f\n", anss[1], anss[2], anss[3], (ans*0.65-1)*2);
    return 0;
}
