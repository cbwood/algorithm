#include <bits/stdc++.h>

using namespace std;

int main(){
  long long l,r;
  // cin >> l >> r;
  string t="1";
  for(int i =0; i < 5; i++){
    string tmp = t;
    for(int i = 0; i < tmp.size(); i++){
      if(tmp[i] == '0') tmp[i] = '1';
      else tmp[i] = '0';
    }
    t+=tmp;
  }
  cout<<t<<endl;
  return 0;
}

/*
1001011001101001011010011001011001101001100101101001011001101001
*/