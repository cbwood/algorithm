/*
 * @File Name          :leetcode-2034.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/23 9:40
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "unordered_map"
#include "set"

using namespace std;

class StockPrice {
public:
    unordered_map<int, int> ma;
    multiset<int> se;
    int maxtime;

    StockPrice() {
        ma.clear();
        se.clear();
        this->maxtime = 0;
    }

    void update(int timestamp, int price) {

        maxtime = max(maxtime, timestamp);
        if (ma[timestamp] != 0) {
            auto it = se.find(ma[timestamp]);
            if (it != se.end()) {
                se.erase(it);
            }
        }
        se.emplace(price);
        ma[timestamp] = price;
    }

    int current() {
        return ma[maxtime];
    }

    int maximum() {
        return *se.rbegin();
    }

    int minimum() {
        return *se.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */