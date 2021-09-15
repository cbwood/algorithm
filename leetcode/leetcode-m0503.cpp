//
// Created by cb on 2021/9/15.
//

#include "iostream"
#include "string"
#include "cmath"
using namespace std;

class Solution{
public:
    int reverseBits(int num){
        int ans = 0;
        int k = 0;
        int t = 0;
        unsigned int tmp = num;
        cout<<tmp<<endl;
        while (tmp){
            if(tmp&1){
                k++;
                t++;
            }else{
                t = k+1;
                k = 0;
            }
            tmp >>= 1;
            ans = max(ans, t);
        }return ans;
    }
};

class Solution1 {
public:
    int reverseBits(int num) {
        int ans = 0;
        int a[50]={0};
        if(num < 0){
            num = -num;
            a[31] = 1;
        }
        int k = 0;
        while(num){
            a[k++] = num&1;
            num >>= 1;
        }k=32;
        int pre[50]={0};
        int post[50]={0};
        if(a[31] == 1){
            for(int i = 0; i < 31; i++)
                a[i] = 1-a[i];
            for(int i = 0; i <= 31; i++){
                a[i] += 1;
                if(a[i] == 2){
                    a[i] = 0;
                }else break;
            }
        }
        for(int i = 1; i < k; i++){
            if(a[i-1] == 0)
                pre[i] = 0;
            else pre[i] = pre[i-1]+1;
        }
        for(int i = k-2; i >= 0; --i){
            if(a[i+1] == 0)
                post[i] = 0;
            else post[i] = post[i+1] + 1;
        }
        for(int i = 0; i < k; i++){
            ans = max(ans, pre[i]+post[i]+1);
        }
        return ans;
    }
};

int main(){
    Solution so;
    cout<<so.reverseBits(-3)<<endl;
    return 0;
}