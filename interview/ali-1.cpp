/*
 *@File Name          :ali-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/25 9:50
 *@Description        :判断账号是否合法
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, bool> ma;
    getchar();
    while (n--) {
        string ss;
        getline(cin, ss);
        int m = ss.size();
        bool check = false;
        for (int i = 0; i < m; i++) {
            if (!isalpha(ss[i])) {
                check = true;
                break;
            }
        }
        if (m < 6 || m > 12)
            cout << "illegal length" << endl;
        else if (m >= 6 && m <= 12 && check) {
            cout << "illegal charactor" << endl;
        } else if (m >= 6 && m <= 12 && !check && ma[ss]) {
            cout << "acount existed" << endl;
        } else {
            cout << "registration complete" << endl;
            ma[ss] = true;
        }

    }
    return 0;
}
