/*************************************************************************
	> File Name: Lightoj1408.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月15日 星期五 09时46分04秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, kase = 0;
    cin >> t;
    while(t--){
        double p;
        int k1, k2;
        cin >> p >> k1 >> k2;
        double ans = 0;
        ans = (k1 - 1) * p + k2 * p;
        cout << ans << endl;
    }return 0;
}
