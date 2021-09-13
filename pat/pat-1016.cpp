#include<bits/stdc++.h>
using namespace std;

struct ss{
    char name[50];
    int time;
    int m,d,h,mm;
    int flag;
}a[1010];

bool cmp(const ss &p, const ss &q){
    if(strcmp(p.name,q.name) != 0)
        return strcmp(p.name,q.name)<0;
    if(p.m != q.m)
        return p.m<q.m;
    return p.time < q.time;
}

int d[30];

void solve(int l, int r){
    if(l == r) return ;
    bool flag = false;
    double ans = 0;
    for(int i = l+1; i <= r; ++i)
        if(!a[i-1].flag&&a[i].flag){
            if(!flag){
                printf("%s %02d\n",a[i].name,a[i].m);
                flag = true;
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $",a[i-1].d,a[i-1].h,a[i-1].mm,a[i].d,a[i].h,a[i].mm,(-1*a[i-1].d*24*60-a[i-1].h*60-a[i-1].mm+a[i].d*24*60+a[i].h*60+a[i].mm));
            double sum = 0;
            sum -= d[a[i-1].h%24]*a[i-1].mm;
            int j = 0;
            while(j + a[i-1].h+a[i-1].d*24 <= a[i].h+a[i].d*24){
                sum += d[(j+a[i-1].h)%24]*60;
                j++;
            }
            sum -= d[a[i].h%24]*(60-a[i].mm);
            sum /= 100;
            printf("%.2f\n",sum);
            ans += sum;
        }
    if(flag) printf("Total amount: $%.2f\n",ans);
    return ;
}

int main(){
    for(int i = 0; i < 24; ++i)
        scanf("%d", &d[i]);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        char st[10];
        int aa,b,c;
        scanf("%s %d:%d:%d:%d %s",a[i].name,&a[i].m, &a[i].d,&a[i].h,&a[i].mm,st);
        //printf("%s %d:%d:%d:%d %s",a[i].name,a[i].m, a[i].d,a[i].h,a[i].mm,st);
        a[i].time = a[i].d*60*60+a[i].h*60+a[i].mm;
        if(st[1] == 'n')
            a[i].flag = 0;
        else a[i].flag = 1;
    }sort(a,a+n,cmp);
    int k = 0;
    for(int i = 1; i < n; ++i)
        if(strcmp(a[i].name,a[i-1].name) != 0 || a[i].m != a[i-1].m){
            solve(k, i-1);
          //  printf("%d------%d\n",k,i-1);
            k = i;
        }
    solve(k,n-1);
    return 0;
}
