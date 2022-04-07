/*
 *@File Name          :fenwickTree-2D.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/7 9:13
 *@Description        :
 *@Function List      :
 *@History            :
 */


const int N = 4100;

int lowbit(int x) {
    return x & (-x);
}

int n, m;
int c[N][N];

/*
 * 单点修改
 */
void update(int x, int y, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) {
            c[i][j] += v;
        }
    }
}

/*
 * 区间修改
 */
void update(int x, int y, int xx, int yy, int v) {
    update(x, y, v);
    update(x + 1, y, -v);
    update(x, y + 1, -v);
    update(x + 1, y + 1, v);
}

/*
 * 单点查询
 */
int query(int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            ans += c[i][j];
        }
    }
    return ans;
}

/*
 * 区间查询
 */
int query(int x, int y, int xx, int yy) {
    return query(xx, yy) - query(x - 1, yy) - query(xx, y - 1) + query(x - 1, y - 1);
}