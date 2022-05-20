/*
 *@File Name          :offer2-059.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/20 8:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "queue"

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int> &nums) {
        cap_ = k;
        for (auto &x: nums) {
            que_.emplace(x);
            if (que_.size() > cap_)
                que_.pop();
        }
    }

    int add(int val) {
        que_.emplace(val);
        if (que_.size() > cap_)
            que_.pop();
        return que_.top();
    }

private:
    priority_queue<int, vector<int>, greater<>> que_;
    int cap_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */