#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    return a+b < b+a;
}

const int maxn = 1e4+10;
string a[maxn];

int  main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a,a+n,cmp);
    string ans="";
    for(int i = 0; i < n;++i)
        ans += a[i];
    while(ans.length()!=0 && ans[0] == '0')
        ans.erase(ans.begin());
    if(ans.length() == 0) cout << 0 << endl;
    else cout << ans << endl;
}