/*
 *@File Name          :offer2-042.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/6 9:08
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "deque"

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        count_ = 0;
    }

    int ping(int t) {
        deq_.push_back(t);
        count_++;
        while (t - 3000 > deq_.front()) {
            deq_.pop_front();
            count_--;
        }
        return count_;
    }

private:
    int count_;
    deque<int> deq_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */