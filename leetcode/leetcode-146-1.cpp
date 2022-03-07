/*
 *@File Name          :leetcode-146-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/7 9:35
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "map"
#include "list"

using namespace std;

class LRUCache {
public:
    list<pair<int, int>> cache;
    map<int, list<pair<int, int>>::iterator> ma;
    int ca;

    LRUCache(int capacity) {
        ca = capacity;
    }

    int get(int key) {
        if (ma.find(key) == ma.end()) return -1;
        auto tmp = *ma[key];
        cache.erase(ma[key]);
        cache.push_front(make_pair(key, tmp.second));
        ma[key] = cache.begin();
        return tmp.second;
    }

    void put(int key, int value) {
        if (ma.find(key) == ma.end()) {
            if (ma.size() == ca) {
                ma.erase(cache.back().first);
                cache.pop_back();
            }
        } else {
            cache.erase(ma[key]);
        }
        cache.emplace_front(make_pair(key, value));
        ma[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */