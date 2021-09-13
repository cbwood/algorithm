#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if(n<10) return n;
        long long sum = 10;
        int k=1;
        int pw = 1;
        while(n>=sum){
            k++;
            pw *= 10;
            sum += k*9*pw;
        }sum -= k*9*pw;
        n -= sum;
        int a = n/k;
        int b =k-1-n%k;
        int ans = pw+a;
        // cout<<ans<<" "<<b<<" "<<k<<endl;
        while(b--){
            ans /= 10;
        }
        return ans%10;
    }
};

int main(){
    Solution so;
    cout << so.findNthDigit(11)<<endl;
}