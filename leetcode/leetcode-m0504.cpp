//
// Created by cb on 2021/9/15.
//

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        vector<int> ans;
        int a[50]={0};
        int k = 0;
        while (num) {
            a[k++] = num & 1;
            num >>= 1;
        }
        int b[50]={0};
        for(int i = 0; i < 32; i++)
            b[i] = a[i];
        int t = 0;
        for(int i = 0; i < 30; i++){
            if(b[i] == 1) t++;
            if(b[i] == 1 && b[i+1] == 0){
                b[i] = 0;
                b[i+1] = 1;
                t--;
                for(int j = i-1; j >= t; j--)
                    b[j] = 0;
                for(int j = t-1; j >= 0; j--)
                    b[j] = 1;
                t=-1;
                int n = 0;
                for(int j = 31; j >= 0; j--)
                    n = n*2+b[j];
                ans.push_back(n);
                break;
            }
        }if(t != -1) ans.push_back(-1);

        for(int i = 0; i < 30; i++)
            b[i] = a[i];
        t = 0;
        for(int i = 0; i < 31; i++){
            if(b[i] == 1) t++;
            if(b[i] == 0 && b[i+1] == 1){
                b[i] = 1;
                b[i+1] = 0;
                for(int j = i-1; j >= i-t; j--)
                    b[j] = 1;
                for(int j = i-t-1; j >= 0; j--)
                    b[j] = 0;
                t=-1;
                int n = 0;
                for(int j = 31; j >= 0; j--)
                    n = n*2+b[j];
                ans.push_back(n);
                break;
            }
        }if(t != -1) ans.push_back(-1);
        return ans;
    }
};

int main() {
    Solution so;
    vector<int> ans = so.findClosedNumbers(2147483647);
    for (auto &x: ans)
        cout << x << endl;
    return 0;
}