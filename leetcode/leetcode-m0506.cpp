//
// Created by cb on 2021/9/15.
//

#include "iostream"
using namespace std;

class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned k = A^B;
        int ans = 0;
//        if(k<0){
//            ans++;
//            k = -k;
//        }
        while(k){
            ans += k&1;
            k /= 2;
        }return ans;
    }
};

int main(){
    Solution so;
    cout<<so.convertInteger(826966453,-729934991)<<endl;
    return 0;
}