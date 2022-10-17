#include <bits/stdc++.h>

using namespace std;

int count(int x){
  int ans = 0;
  while(x){
    ans += (x&1);
    x = x/2;
  }
  return ans;
}

int main(){
  int n,k;
  cin >> n >> k;
  priority_queue<pair<int, int>, deque<pair<int, int>>, less<>> que;
  while(n--){
    int x;
    cin >> x;
    que.push({x-count(x), x});
  }
  while(!que.empty() && k--){
    auto t = que.top();
    que.pop();
    int cur = count(t.second);
    if(count(cur)){
      que.push({cur-count(cur), cur});
    }
  }
  long long ans = 0;
  while(!que.empty()){
    auto t = que.top();
    que.pop();
    ans += t.second;
  }
  cout<<ans<<endl;
  return 0;
}