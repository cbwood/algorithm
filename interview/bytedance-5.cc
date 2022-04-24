/*
 *@File Name          :bytedance-5.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 13:12
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"

using namespace std;

vector<string> ans;
bool vis[10];
vector<int> seg(4);
map<char, int> ma;

void dfs(const string &s, int idx, int cur) {
    if (idx == 4) {
        if (cur == s.size()) {
            string t;
            for (int i = 0; i < 4; i++) {
                t += to_string(seg[i]);
                if (i != 3)
                    t += '.';
            }
            ans.push_back(move(t));
        }
        return;
    }
    if (cur == s.size()) return;

    if (s[cur] == '0') {
        seg[idx] = 0;
        dfs(s, idx + 1, cur + 1);
    }

    int addr = 0;
    for (int i = cur; i < s.size(); i++) {
        addr = addr * 10 + s[i] - '0';
        if (addr > 0 && addr <= 255) {
            seg[idx] = addr;
            dfs(s, idx + 1, i + 1);
        } else break;
    }
}

void dfs(string &s, int cur) {
    if (cur == s.size()) {
        dfs(s, 0, 0);
//cout<<s<<endl;
        return;
    }
    if (isdigit(s[cur]))
        dfs(s, cur + 1);
    else {
        if (ma[s[cur]]) {
            char tmp = s[cur];
            s[cur] = (ma[s[cur]] - 1) + '0';
            dfs(s, cur + 1);
            s[cur] = tmp;
        } else
            for (int i = 1; i <= 10; i++) {
                if (!vis[i - 1]) {
                    vis[i - 1] = true;
                    ma[s[cur]] = i;
                    char tmp = s[cur];
                    s[cur] = (ma[s[cur]] - 1) + '0';
                    dfs(s, cur + 1);
                    s[cur] = tmp;
                    ma[s[cur]] = 0;
                    vis[i - 1] = false;
                }
            }
    }
}

int main() {
    string s;
    cin >> s;
    for (auto &x: s) {
        if (isdigit(x))
            vis[x - '0'] = true;
    }
    dfs(s, 0);
    for (auto &x: ans)
        cout << x << endl;
    return 0;
}