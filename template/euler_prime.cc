/*
 *@File Name          :euler_prime.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/25 11:02
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e5 + 10;
bool vis[MAXN];
int pri[MAXN];
int cnt = 0;

// C++ Version
void init() {
    for (int i = 2; i < MAXN; ++i) {
        if (!vis[i]) {
            pri[cnt++] = i;
        }
        for (int j = 0; j < cnt; ++j) {
            if (1ll * i * pri[j] >= MAXN) break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    init();
    return 0;
}