/*
 *@File Name          :offer2-031.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/29 9:15
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "list"
#include "map"

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : ca(capacity) {

    }

    int get(int key) {
        if (ma.find(key) == ma.end())
            return -1;
        auto tmp = ma[key];
        auto t = *tmp;
        li.erase(tmp);
        li.push_front(t);
        ma[key] = li.begin();
        return t.second;
    }

    void put(int key, int value) {
        if (ma.find(key) == ma.end()) {
            if (li.size() == ca) {
                ma.erase(li.back().first);
                li.pop_back();
            }
        } else {
            li.erase(ma[key]);
        }
        li.push_front({key, value});
        ma[key] = li.begin();
    }

private:
    list<pair<int, int>> li;
    map<int, list<pair<int, int>>::iterator> ma;
    int ca;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */