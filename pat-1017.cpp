#include<bits/stdc++.h>
using namespace std;

class ss{
    public:
    int t,pt,wt,id,st;
    bool operator < (const ss &p)const{
        return st+pt>p.st+p.pt;
    }
}a[10000+10];

bool cmp(const ss &p, const ss &q){
    return p.t < q.t;
}

int main(){
    int n,k;
    int st = 8*60*60;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        int h,m,s;
        scanf("%d:%d:%d %d", &h, &m,&s,&a[i].pt);
        a[i].pt *= 60;
        a[i].t = h*60*60+m*60+s;
        a[i].wt = 0;
    }
    sort(a,a+n,cmp);
    priority_queue<ss> que;
    int num = 0;
    for(int i = 0; i < k && i < n; ++i)
        if(a[i].t <17*60*60+1){
            a[i].id = i;
            num++;
            a[i].st = a[i].t;
            if(a[i].t < st){
                a[i].st = st;
                a[i].wt = st-a[i].t;
            }
            que.push(a[i]);
        }
    double sum = 0;
    while(!que.empty()){
        ss tmp = que.top();
        que.pop();
        sum += tmp.wt;
        if(k < n && a[k].t <17*60*60+1){
            if(tmp.st+tmp.pt > a[k].t){
                tmp.st = tmp.st + tmp.pt;
                tmp.wt = tmp.st-a[k].t;
                tmp.pt = a[k].pt;
            }else {
                tmp.st = a[k].t;
                tmp.pt = a[k].pt;
                tmp.wt = 0;
            }
            num++;
            k++;
            que.push(tmp);
        }
    }
    printf("%.1f\n",sum/60/num);
    return 0;
}
