#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  while(q--){
    int opt,i,x;
    cin >> opt >> i >> x;
    if(opt == 1){
      a[i] = x;
    }else{
      int ans = 0;
      for(int j = 1; j <= i; j++){
        ans += (a[j] == x);
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}