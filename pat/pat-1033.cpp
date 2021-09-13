#include<bits/stdc++.h>
using namespace std;

struct ss{
    double p,x;
}a[1000];

bool cmp(const ss &p, const ss &q){
    if(p.x == q.x)
        return p.p < q.p;
    return p.x < q.x;
}

int main(){
    int c,d,dv,n;
    scanf("%d %d %d %d", &c, &d, &dv, &n);
    for(int i = 0; i < n; ++i)
        scanf("%lf %lf", &a[i].p, &a[i].x);
    sort(a,a+n,cmp);
    a[n].p=0;
    a[n].x=d;
    n++;
    double ansp=0,ansx=0, prep = 1000000;
    double cp=0,cc=0;
    int k = 0;
    while(k < n){
        int i = k;
        bool flag = true;
        double minp=100000;
        while(k < n && ansx+cc*dv >= a[k].x){
            if(prep > a[k].p){
                i = k;
                flag = false;
                ansp += ((a[i].x-ansx)/dv-cp)*prep;
                prep = a[i].p;
                ansx = a[i].x;
                cp = 0;
                break;
            }k++;
        }if(flag){
            k=i;
            while(k < n && ansx+cc*dv >= a[k].x){
                if(minp > a[k].p){
                    i = k;
                    flag = false;
                    minp = a[k].p;
                }k++;
            }if(!flag){
                ansp += (cc-cp)*prep;
                cp = cc-(a[i].x-ansx)/dv;
                ansx = a[i].x;
                prep = a[i].p;
            }
        }if(flag){
            ansx += cc*dv;
            break;  
        }cc=c;
        k = i+1;
    }if(ansx < d)
        printf("The maximum travel distance = %.2f\n",ansx);
    else printf("%.2f\n",ansp);
}

/*
50 1300 12 7
6.00 1250
7.00 600
7.00 150
7.20 200
7.50 400
7.30 1000
6.85 300
*/