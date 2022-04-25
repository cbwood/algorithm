/*
 *@File Name          :tencent-0.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 19:58
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    vector<string> vec;
    cin >> n;
    int maxn = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vec.emplace_back(s);
        maxn = max(maxn, (int) s.size());
    }

    vector<int> ans;
    for (int i = 0; i < maxn; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (vec[j].size() > i) {
                tmp = tmp * 10 + vec[j][i] - '0';
            }
        }
        ans.emplace_back(tmp);
    }
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << " ";
    cout << ans.back() << endl;
    return 0;
}