#include<bits/stdc++.h>
using namespace std;

struct ss{
    int x,y;
};
struct sss{
    string x;
    int y;
};

const int maxn = 2e3+10;
map<int, string> mb;
map<string, int> ma;
vector<int> w[maxn],an;
vector<ss> v[maxn];
vector<sss> ans;
bool vis[maxn];
int sb[maxn][maxn];

bool cmp(const sss &p, const sss &q){
    return p.x < q.x;
}

void dfs(int i, vector<int> &an){
    vis[i] = 1;
    an.push_back(i);
    for(auto &x : w[i])
        if(!vis[x])
            dfs(x, an);
}

int main(){
    int n,k;
    cin >> n >> k;
    int t=0;
    ss tmp;
    string ch1, ch2; 
    for(int i = 0; i < n; ++i){
        cin >> ch1 >> ch2 >> tmp.y;
        if(ma[ch1] == 0)
            ma[ch1] = ++t,mb[t]=ch1;
        if(ma[ch2] == 0)
            ma[ch2]=++t,mb[t]=ch2;
        tmp.x = ma[ch2];
        sb[ma[ch1]][ma[ch2]] += tmp.y;
        sb[ma[ch2]][ma[ch1]] += tmp.y;
        v[ma[ch1]].push_back(tmp);
        w[ma[ch1]].push_back(ma[ch2]);
        w[ma[ch2]].push_back(ma[ch1]);
    }for(int i = 1; i <= t; ++i)
        if(!vis[i]){
            an.clear();
            int num=0;
            dfs(i, an);
            if(an.size() <= 2) continue;
            for(auto &x : an){
                for(auto &y : v[x])
                    num += y.y;
            }
            sss tmpp;
            tmpp.y = an.size();
            if(num <= k) continue;
            int tt = 0;
            int tmpx;
            for(auto &x : an){
                int sum = 0;
                for(int j = 1; j <= t; ++j)
                    sum += sb[x][j];
                if(sum > tt){
                    tt = sum;
                    tmpx = x;
                }
            }tmpp.x = mb[tmpx];
            ans.push_back(tmpp);
        }
        sort(ans.begin(), ans.end(), cmp);
        cout << ans.size() << endl;
        for(auto &x: ans)
            cout << x.x << " " << x.y << endl;
    return 0;
}