#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long LL;
const int mod = 1e8;
char ss[110], a[110], b[110], bit[110];
int dp[101][101][10];
int slen, alen;

bool check(int pre, int cur, char ch){
    if(ch == '/')
        return pre < cur;
    else if(ch == '-')
        return pre == cur;
    else return pre > cur;
}

int dfs(int len, int pos, int pre, bool limit, bool lead){
    if(len == alen)
        return pos == slen;
    if(!lead && !limit && dp[len][pos][pre] != -1)
        return dp[len][pos][pre];
    int up = limit ? (bit[len]-'0') : 9;
    int tmp = 0;
    for(int i = 0; i <= up; ++i){
        if(lead)
            tmp += dfs(len+1, pos, i, limit && i == up, lead && i == 0);
        else if(pos < slen && check(pre,i, ss[pos]))
            tmp += dfs(len+1, pos+1, i, limit && i == up, lead && i == 0);
        else if(pos > 0 && check(pre, i, ss[pos-1]))
            tmp += dfs(len+1, pos, i, limit && i == up, lead && i == 0);
        tmp %= mod;
    }if(!limit && !lead) dp[len][pos][pre] = tmp;
    return tmp;
}

int solve(char x[], int t){
    alen =strlen(x);
    int st = 0;
    while(x[st] == '0')
        ++st;
    if(st >= alen)
        return 0;
    if(t)
        for(int i = alen-1; i >= st; --i)
            if(x[i] >= '1'){
                x[i]--;
                break;
            }else x[i] = '9';
    strcpy(bit, x);memset(dp, -1, sizeof(dp));
    return dfs(st, 0, 0, true, true);
}

int main(){
    while(scanf(" %s", ss) != EOF){
        scanf(" %s %s",a , b);
        slen =strlen(ss);
        int ans = solve(b,0) - solve(a,1);
        printf("%08d\n",(ans % mod + mod) % mod);
    }return 0;
}
