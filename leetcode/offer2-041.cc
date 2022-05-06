/*
 *@File Name          :offer2-041.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/6 9:03
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "deque"

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capaity_ = size;
        size_ = 0;
        sum_ = 0;
    }

    double next(int val) {
        sum_ += val;
        size_++;
        deq_.push_back(val);
        if (size_ > capaity_) {
            size_--;
            sum_ -= deq_.front();
            deq_.pop_front();
        }
        return sum_ * 1.0 / size_;
    }

private:
    int capaity_;
    int size_;
    int sum_;
    deque<int> deq_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */