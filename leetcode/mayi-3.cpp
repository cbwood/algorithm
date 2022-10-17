#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  if(n % 4== 2){
    cout<<-1<<endl;
    return 0;
  }
  vector<vector<int>> a(n, vector<int>(n, 0));
  vector<int> nums{2,1};
  if(n % 4 == 1) swap(nums[1], nums[0]);
  for(int i = 0; i < n; i++){
    int tmp = i % 4;
    for(int j = 0; j < n; j++){
      a[i][j] = nums[tmp/2];
      nums[tmp/2]+=2;
      tmp++;
      tmp = tmp%4;
    }
  }
  for(auto &x: a){
    for(int j = 0; j < x.size()-1; j++){
      cout<<x[j]<<" ";
    }
    cout<<x.back()<<endl;
  }
  return 0;
}