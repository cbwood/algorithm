#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
struct ss{
    char id[100];
    char st[100];
    char ed[100];
}a[maxn];

bool cmp(const ss &sa, const ss &sb){
    return strcmp(sa.st, sb.st) < 0;
}


bool ccmp(const ss &sa, const ss &sb){
    return strcmp(sa.ed, sb.ed) < 0 ;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf(" %s %s %s",a[i].id, a[i].st, a[i].ed);
    sort(a,a+n,cmp);
    printf("%s ",a[0].id);
    sort(a,a+n,ccmp);
    printf("%s\n",a[n-1].id);
    return 0;
}
