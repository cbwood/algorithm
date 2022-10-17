#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  long long k;
  cin >> s >> k;
  long long tmp = 0;
  int n = s.size();
  int l = 0, r = 0;
  map<int, long long> ma;
  tmp = 1;
  for(int i = 0; i < 10; i++){
    ma[i] = tmp;
    tmp = tmp * 10;
  }
  tmp = 0;
  long long ans = 0;
  while(r < n){
    tmp = tmp * 10 + s[r]-'0';
    
    while(tmp >= k){
      tmp = tmp % ma[r-l];
      l++;
    }
    r++;
    ans = ans + r-l;
  } 
  cout<<ans<<endl;
  return 0;
}