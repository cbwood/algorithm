#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

struct ss{
    LL id;
    int sco;
    int loc;
    int lk;
}a[100000],b[1000];
int num[1000], sc[1000],rak[1000];

bool cmp(const ss &p, const ss &q){
    if(p.sco == q.sco)
        return p.id < q.id;
    return p.sco > q.sco;
}

int main(){
    int n;
    int in = 0;
    memset(rak, 1, sizeof rak);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; ++j){
            scanf("%lld %d", &b[j].id, &b[j].sco);
            b[j].loc = i;
        }
        sort(b,b+k,cmp);
        int pre = 1;
        for(int j = 0; j < k; ++j){
            if(b[j].sco != b[j-1].sco)
                pre = j+1;
            b[j].lk = pre;
            a[++in] = b[j];
        }
    }sort(a+1,a+in+1,cmp);
    int x = 1;
    printf("%d\n",in);
    a[0].sco = -1;
    for(int i = 1; i < in; ++i){
        if(a[i].sco != a[i-1].sco){
            x = i;
        }
        printf("%013lld %d %d %d\n",a[i].id, x, a[i].loc,a[i].lk);
    }
    return 0;
}/*
2
5
0234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
*/
