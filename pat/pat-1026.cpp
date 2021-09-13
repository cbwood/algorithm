#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int num[maxn];
int vis[maxn];

class ss{
public:
    int tag,st,pt,wt,id;
    bool operator < (const ss &p)const{
        if(st + wt + pt !=  p.st + p.wt + p.pt)
            return st + wt +pt > p.st + p.wt + p.pt;
        return id > p.id;
    }
}a[maxn],b[maxn];

struct cmpx{
    bool operator()(ss &a, ss &b) const{
        return a.st+a.wt > b.st+b.wt;
    }
};

bool cmp(const ss &p, const ss &q){
    return p.st < q.st;
}

int main(){
    int n;
    int k,m;
    scanf("%d", &n);
    for(int i = 0;i < n; ++i){
        int x,y,z;
        scanf("%d:%d:%d %d %d",&x,&y,&z,&a[i].pt,&a[i].tag);
        a[i].pt = min(a[i].pt*60,2*60*60);
        a[i].st = x*60*60+y*60+z;
    }scanf("%d %d", &k, &m);
    for(int i = 0; i < m; ++i){
        int x;
        scanf("%d", &x);
        vis[x] = 1;
    }
    sort(a,a+n,cmp);
    priority_queue<ss> que;
    priority_queue<ss, vector<ss>, cmpx > ans;
    int sd = 8*60*60, ed = 21*60*60-1;
    for(int i = 0; i < k && i < n; ++i){
        if(a[i].st <= ed){
            a[i].id = i+1;
            num[i+1]++;
            /*if(a[i].st < sd){
                a[i].wt = sd - a[i].st;
            }*/que.push(a[i]);
            ss tmp = a[i];
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",tmp.st/60/60,tmp.st/60%60,tmp.st%60,(tmp.st+tmp.wt)/60/60,(tmp.st+tmp.wt)/60%60,(tmp.st+tmp.wt)%60,(tmp.wt+30)/60);
        }
    }
    int fx = k;
    while(!que.empty()){
        ss tmp = que.top();
        que.pop();
        //ans.push(tmp);
        int x = k;
        for(int i = k+1; i < n; ++i)
            if(a[i].tag && !a[i].id && a[i].st <= ed && tmp.st+tmp.wt+tmp.pt-a[i].st >= 0 && tmp.st+tmp.wt+tmp.pt<= ed){
                x = i;
                break;
        }
      //  printf("%d %02d:%02d:%02d %02d:%02d:%02d %d\n",tmp.id, tmp.st/60/60,tmp.st/60%60,tmp.st%60,(tmp.st+tmp.wt)/60/60,(tmp.st+tmp.wt)/60%60,(tmp.st+tmp.wt)%60,(tmp.wt+30)/60);
        if(x != k){
            b[0] = tmp;
            int kkk = 1;
            while(!que.empty()){
                b[kkk] = que.top();
                if(b[kkk].st+b[kkk].wt+b[kkk].pt != tmp.st+tmp.pt+tmp.wt)
                    break;
                kkk++;
                que.pop();
            }
            int xx = 0;
            for(int i = 0; i < kkk; ++i)
                if(vis[b[i].id]){
                    xx = i;
                    break;
                }
            for(int i = 0; i < kkk; ++i)
                if(xx != i)
                    que.push(b[i]);
            tmp = b[xx];
            ans.push(tmp);
            if(vis[tmp.id] && tmp.st+tmp.wt+tmp.pt <= ed){
                tmp.wt = max(0, tmp.st+tmp.wt+tmp.pt-a[x].st);
                tmp.st = a[x].st;
                tmp.pt = a[x].pt;
                tmp.tag = a[x].tag;
                num[tmp.id]++;
                que.push(tmp);
                printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",tmp.st/60/60,tmp.st/60%60,tmp.st%60,(tmp.st+tmp.wt)/60/60,(tmp.st+tmp.wt)/60%60,(tmp.st+tmp.wt)%60,(tmp.wt+30)/60);
                a[x].id = 1;
            }else {
                while(k < n && tmp.st+tmp.wt+tmp.pt <= ed && a[k].st <= ed){
                    if(a[k].id){k++; continue;}
                    tmp.wt = max(0, tmp.st+tmp.wt+tmp.pt-a[k].st);
                    tmp.st = a[k].st;
                    tmp.pt = a[k].pt;
                    tmp.tag = a[k++].tag;
                    num[tmp.id]++;
                    que.push(tmp);
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",tmp.st/60/60,tmp.st/60%60,tmp.st%60,(tmp.st+tmp.wt)/60/60,(tmp.st+tmp.wt)/60%60,(tmp.st+tmp.wt)%60,(tmp.wt+30)/60);
                    break;
                }
            }
        }else{
            ans.push(tmp);
            while(k < n && tmp.st+tmp.wt+tmp.pt <= ed && a[k].st <= ed){
                if(a[k].id){k++; continue;}
                tmp.wt = max(0, tmp.st+tmp.wt+tmp.pt-a[k].st);
                tmp.st = a[k].st;
                tmp.pt = a[k].pt;
                tmp.tag = a[k++].tag;
                num[tmp.id]++;
                que.push(tmp);
                printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",tmp.st/60/60,tmp.st/60%60,tmp.st%60,(tmp.st+tmp.wt)/60/60,(tmp.st+tmp.wt)/60%60,(tmp.st+tmp.wt)%60,(tmp.wt+30)/60);
                break;
            }
        }
    }/*while(!ans.empty()){
        ss tmp = ans.top();
        ans.pop();
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",tmp.st/60/60,tmp.st/60%60,tmp.st%60,(tmp.st+tmp.wt)/60/60,(tmp.st+tmp.wt)/60%60,(tmp.st+tmp.wt)%60,(tmp.wt+30)/60);
    }*/
    for(int i = 1; i < fx; ++i)
        printf("%d ", num[i]);
    printf("%d\n", num[fx]);
    return 0;
}
