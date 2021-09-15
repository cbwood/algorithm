//
// Created by cb on 2021/9/15.
//
#include "string"
#include "iostream"
using namespace std;


class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        int k = 32;
        while(num > 0 && k > 0){
            k--;
            num = num*2;
            ans += to_string(int(num));
            num = num-int(num);

        }if(k > 0) return ans;
        return "ERROR";
    }
};

int main(){
    Solution so;
    cout<<so.printBin(0.1)<<endl;
}