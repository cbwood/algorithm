#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
struct ss{
    int id,gr;
    char name[20];
}a[maxn];

bool com1(const ss &p, const ss &q){
    return p.id < q.id;
}

bool com2(const ss &p, const ss &q){
    return strcmp(p.name, q.name) <= 0;
}

bool com3(const ss &p, const ss &q){
    return p.gr <= q.gr;
}

int main(){
    int n,c;
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; ++i){
        scanf("%d %s %d", &a[i].id, a[i].name, &a[i].gr);
    }
    if(c == 1)
        sort(a,a+n, com1);
    else if(c == 2)
        sort(a,a+n,com2);
    else sort(a,a+n,com3);
    for(int i = 0; i < n; ++i){
        printf("%06d %s %d\n",a[i].id, a[i].name, a[i].gr);
    }
    return 0;
}