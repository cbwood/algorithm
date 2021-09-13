#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        int ans = 1;
        n--;
        priority_queue<int,vector<int>,greater<int> > que[3];
        int k = ans;
        set<int> se;
        se.insert(1);
        int tk[3] = {2,3,5};
        for(int i = 0; i <3; i++)
            que[i].push(tk[i]);
        int tmp = que[0].top();
        while(n--){
            k = 0;
            ans = que[0].top();
            for(int i = 0; i < 3; ++i){
                if(que[i].top()<ans &&se.count(que[i].top()) == 0){
                    k=i;
                    ans = que[i].top();
                }
            }que[k].pop();
            se.insert(ans);
            
            for(int i = 0; i < 3;++i){
                while(que[i].top() == ans)
                    que[i].pop();
                que[i].push(ans*tk[i]);
            }
        }return ans;
    }
};

int main(){
    Solution so;
    cout<<so.nthUglyNumber(10)<<endl;
    return 0;
}