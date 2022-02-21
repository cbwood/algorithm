#include<algorithm>
#include<queue>
#include<string>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> que;
        que.emplace(a,'a');
        que.emplace(b,'b');
        que.emplace(c,'c');
        string ans="";

        while(!que.empty()){
            pair<int,char> t = que.top();
            que.pop();
            int n = ans.size();
            if(n >= 2 && ans[n-2] == t.second && ans[n-1] == t.second){
                if(que.empty()) break;
                pair<int,char> p = que.top();
                que.pop();
                if(p.first > 0){
                    ans.push_back(p.second);
                    p.first--;
                    if(p.first > 0) que.emplace(p);
                }
                que.emplace(t);
            }else if(t.first > 0 ){
                t.first--;
                ans.push_back(t.second);
                if(t.first > 0) que.emplace(t);
            }
        }return ans;
    }
};
