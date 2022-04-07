/*
 *@File Name          :ksyun-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/6 20:45
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define lowbit(x) (x&-x)
const int N = 500 + 3;
int n, m;

struct BitTree2D {
    ll c[N][N];

    inline void add(int x, int y, int k) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                c[i][j] += k;
            }
        }
    }

    inline ll find(int x, int y) {
        ll res = 0;
        for (int i = x; i; i -= lowbit(i)) {
            for (int j = y; j; j -= lowbit(j)) {
                res += c[i][j];
            }
        }

        return res;
    }

    inline ll query(int sx, int sy, int fx, int fy) {
        return find(fx, fy) - find(fx, sy - 1) - find(sx - 1, fy) + find(sx - 1, sy - 1);
    }
} t;

int a[502][502];

int main() {
    int c;
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            t.add(i + 1, j + 1, a[i][j]);
        }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = ans; k < min(n, m); k++)
                if (i + k < n && j + k < m) {
                    ll tmp = t.query(i + 1, j + 1, i + k + 1, j + k + 1);
                    cout << tmp << endl;
                    if (tmp <= c && k > ans) {
                        ans = k;
                    }
                }
        }
    }
    cout << (ans + 1) * (ans + 1) << endl;
    return 0;
}

/*
 *
3 3 4
3 3 3
3 1 1
3 1 1
 */