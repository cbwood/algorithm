#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long ans = 0;
    long long t = 1;
    long long m = 1;
    long long k = 1;
    while(n > 0){
        ans += t * min(k, n);
        n -=  k;
        k *= 2;
        t++;
    }
    cout<<ans<<endl;
    return 0;
}