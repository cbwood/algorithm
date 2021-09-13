#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int num[maxn];
int pre[maxn];

int main(){
    int st,stt,n;
    int numx = 0;
    int ans;
    memset(pre, -1, sizeof(pre));
    scanf("%d %d %d", &st, &stt, &n);
    for(int i = 0; i < n; ++i){
        int x,y;
        char ch;
        scanf("%d %c %d", &x, &ch, &y);
        pre[x] = y;
    }
    int x = st;
    while(x != -1){
        num[x]++;
        x = pre[x];
    }
    x = stt;
    while(x != -1){
        if( num[x] == 1){
            printf("%05d\n",x);
            return 0;
        }
        x = pre[x];
    }
    printf("-1");
    return 0;
}