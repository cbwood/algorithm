#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        long long mod = 1e9+7;
        if (n == 0) return 0;
        if(n <= 2) return 1;
        long long a=1, b=1;
        n -=2;
        while(n--){
            int tmp = (a+b)%mod;
            b = a;
            a = tmp;
        }return a;
    }
};

int main(){
    Solution so;
    cout << so.fib(45)<< endl;
    return 0;
}