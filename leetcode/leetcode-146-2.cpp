/*
 *@File Name          :leetcode-146-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/13 10:38
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "list"
#include "map"
using namespace std;

class LRUCache {
 public:
  map<int, list<pair<int, int>>::iterator> cache;
  list<pair<int, int>>                     li;
  int                                      ca;

  LRUCache(int capacity) { ca = capacity; }

  int get(int key) {
    if (cache.count(key)) {
      auto tmp = cache[key]->second;

      li.erase(cache[key]);
      li.push_front({key, tmp});

      cache[key] = li.begin();
      return cache[key]->second;
    }
    return -1;
  }

  void put(int key, int value) {
    if (cache.count(key) == 0) {
      if (cache.size() == ca) {
        cache.erase(li.back().first);
        li.pop_back();
      }
    } else {
      li.erase(cache[key]);
    }
    li.push_front({key, value});
    cache[key] = li.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */