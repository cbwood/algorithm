/*
 *@File Name          :fenwickTree-1D.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/7 8:59
 *@Description        :一维树状数组
 *@Function List      :
 *@History            :
 */

const int N = 1e6 + 10;

int c[N];
int n;

int lowbit(int x) {
    return x & (-x);
}

/*
 * 单点修改
 */
void update(int x, int v) {
    while (x <= n) {
        c[x] += v;
        x += lowbit(x);
    }
}

/*
 * 区间修改
 */
void update(int l, int r, int v) {
    update(l, v);
    update(r + 1, -v);
}


/*
 * 前缀和
 */
int getSum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

/*
 * 区间和
 */
int getSum(int l, int r) {
    return getSum(r) - getSum(l - 1);
}