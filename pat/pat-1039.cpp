#include<bits/stdc++.h>
using namespace std;

const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> a[maxn];

int solve(char *s){
    int ans = 0;
    for(int i = 0; i < 3; ++i)
        ans = ans*26+s[i]-'A';
    ans = ans*10+s[3]-'0';
    return ans;
}

int main(){
    int n,k;
    scanf("%d %d", &k, &n);
    char na[5];
    for(int i = 0; i < n; ++i){
        int x,y;
        scanf("%d %d", &x, &y);
        while(y--){
            scanf("%s", na);
            int ans = solve(na);
            a[ans].push_back(x);
        }
    }while(k--){
        scanf("%s", na);
        int ans = solve(na);
        printf("%s %d", na,a[ans].size());
        sort(a[ans].begin(), a[ans].end());
        for(auto &x : a[ans])
            printf(" %d", x);
        printf("\n");
    }return 0;
}