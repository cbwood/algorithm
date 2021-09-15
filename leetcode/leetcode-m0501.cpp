//
// Created by cb on 2021/9/15.
//

class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        int a[50] = {0}, b[50]={0};
        int k = 0;
        while (M){
            b[k++] = M%2;
            M>>=1;
        }k = 0;
        while(N){
            a[k++] = N%2;
            N >>= 1;
        }
        int ans = 0;
        k = max(k, j+1);
        for(int t = i; t <= j; ++t)
            a[t] = b[t-i];
        for(int t = k-1; t >= 0; --t)
            ans = ans*2+a[t];
        return ans;
    }
};