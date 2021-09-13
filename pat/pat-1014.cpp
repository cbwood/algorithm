#include<bits/stdc++.h>
using namespace std;

class ss{
    public:
    int x,y,id;
    ss(){}
    ss(int x, int y, int id)
    :x(x),y(y),id(id){}
    bool operator <(const ss &p)const{
        if(y != p.y)
            return y > p.y;
        return x > p.x;
    }
}tmp;
int ans[1100],t[110],w[1010];

int main(){
    int n,m,k,q;
    priority_queue<ss> que;
    queue<ss> line[100];
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 1; i <= k; ++i)
        scanf("%d", &w[i]);
    int p = 0;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n && p < k; j++){
            t[j] += w[++p];
            tmp.id = p;
            tmp.x = j;
            tmp.y = t[j];
            if(i == 1)
                que.push(tmp);
            else line[j].push(tmp);
        }
    while(!que.empty()){
        tmp = que.top();
        que.pop();

        //printf("id = %d %d:%d\n", tmp.id, tmp.y/60+8,tmp.y%60 );
        ans[tmp.id] = tmp.y;
        if(p < k){
            tmp.id = ++p;
            t[tmp.x] += w[p];
          //  printf("%d %d %d\n",tmp.id, tmp.x, t[tmp.x]);
            tmp.y = t[tmp.x];
            line[tmp.x].push(tmp);
            que.push(line[tmp.x].front());
            line[tmp.x].pop();
        }
    }for(int i = 0; i < 100; ++i)
        while(!line[i].empty()){
            tmp = line[i].front();
            line[i].pop();
            ans[tmp.id] = tmp.y;
        }

    while(q--){
        int x,a=8,b=0;
        scanf("%d", &x);
        a += ans[x]/60;
        b += ans[x]%60;
        if((ans[x]-w[x])/60+8>= 17 &&(ans[x]-w[x]))
            printf("Sorry\n");
        else printf("%02d:%02d\n",a,b);
    }return 0;
}
