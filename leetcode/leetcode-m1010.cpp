//
// Created by cb on 2021/9/17.
//

class StreamRank {
public:
    StreamRank() {
        memset(c, 0, sizeof(c));
    }

    void track(int x) {
        x++;
        while(x < maxn){
            c[x] += 1;
            x += lowbit(x);
        }
    }

    int getRankOfNumber(int x) {
        int ans = 0;
        x++;
        while(x > 0){
            ans += c[x];
            x -= lowbit(x);
        }return ans;
    }

    int lowbit(int x){
        return x&(-x);
    }

private:
    int c[50005];
    int maxn = 50005;
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */