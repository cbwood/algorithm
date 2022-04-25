/*
 *@File Name          :tencent-1.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 20:10
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param a int整型vector
     * @return int整型
     */
    const int maxn = 2e5 + 10;

    int getNumber(vector<int> &a) {
        // write code here

        vector<bool> p(maxn, false);
        for (int i = 2; i < maxn; i++) {
            bool check = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    check = false;
                    break;
                }
            }
            p[i] = check;
        }

        int n = a.size();
        while (n > 1) {
            int k = 0;
            for (int i = 1; i < n; i++) {
                if (p[i + 1]) {
                    swap(a[k++], a[i]);
                }
            }
            n = k;
        }
        return a[0];
    }
};