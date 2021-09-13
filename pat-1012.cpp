#include<bits/stdc++.h>
using namespace std;

struct ss{
    char name[10];
    int w;
    int r;
}a[10][100000];

bool cmp(const ss &p, const ss &q){
    return p.w > q.w;
}

int main(){
    int n,mm;
    scanf("%d %d", &n, &mm);
    for(int i = 0; i < n; ++i){
        int x,y,z;
        char name[10];
        scanf(" %s %d %d %d", name,&x,&y,&z);
        a[0][i].w = (x+y+z+0.5)/3;
        for(int j = 0; j <= 3; ++j)
            strcpy(a[j][i].name, name);
        a[1][i].w = x;
        a[2][i].w = y;
        a[3][i].w = z;
    }sort(a[0],a[0]+n,cmp);
    sort(a[1],a[1]+n,cmp);
    sort(a[2],a[2]+n,cmp);
    sort(a[3],a[3]+n,cmp);
    for(int i = 0; i <= 3; ++i){
        a[i][0].r = 1;
        for(int j = 1; j < n; ++j)
            if(a[i][j].w < a[i][j-1].w)
            a[i][j].r = j+1;
        else a[i][j].r = a[i][j-1].r;
    }
    while(mm--){
        char x[10];
        scanf(" %s", x);
        bool flag = false;
        int t = n+1;
        char na;
        for(int j = 0; j < n && !flag; ++j)
            for(int i = 0; i <= 3; ++i)
                if(strcmp(x, a[i][j].name) == 0 && a[i][j].r < t){
                    t = a[i][j].r;
                    if(i == 0)
                        na = 'A';
                    else if(i == 1)
                        na = 'C';
                    else if(i == 2)
                        na = 'M';
                    else if(i == 3)
                        na = 'E';
                    flag = true;
                }
        if(flag){
            printf("%d %c\n",t, na);
        }else printf("N/A\n");
    }return 0;
}
