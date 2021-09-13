#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <string>

using namespace std;
typedef long long LL;
#define sqr(x) (x) * (x)
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 10;

bool cmp(const vector<int> &p, const vector<int> &q){
    return p[0]<q[0];
}

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if(restrictions.size()==0) return n-1;
        sort(restrictions.begin(), restrictions.end(), cmp);
        int pre=0;
        int preid=1;
        int nn = restrictions.size();
        int ans=restrictions[nn-1][1]+n-restrictions[nn-1][0];
        for(auto &x: restrictions){
            if(x[1]>=pre){
                if(x[1]-pre>=x[0]-preid){
                    ans = max(ans,pre+x[0]-preid);
                    pre=pre+x[0]-preid;
                    preid=x[0];
                }else {
                    ans = max(ans, x[1]+(x[0]-preid-(x[1]-pre))/2);
                    preid=x[0];
                    pre=x[1];
                }
            }else {
                if(pre-x[1]>=x[0]-preid){
                    ans = max(ans,x[1]);
                    preid=x[0];
                    pre=x[1];
                }else {
                    ans = max(ans, pre+(x[0]-preid-(pre-x[1]))/2);
                    preid=x[0];
                    pre=x[1];
                }
            }
        }return ans;
    }
};

int main()
{
    cout<<'1'<<endl;
    return 0;
}