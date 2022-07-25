/*
 *@File Name          :leetcode-w303-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/24 10:19
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class FoodRatings {
 public:
  map<string, pair<string, int>>      fd;
  map<string, set<pair<int, string>>> ma;
  FoodRatings(vector<string>& foods, vector<string>& cuisines,
              vector<int>& ratings) {
    int n = foods.size();
    for (int i = 0; i < n; i++) {
      fd[foods[i]] = {cuisines[i], ratings[i]};
      ma[cuisines[i]].insert({ratings[i], foods[i]});
    }
  }

  void changeRating(string food, int newRating) {
    auto t = fd[food];
    ma[t.first].erase({t.second, food});
    ma[t.first].insert({newRating, food});
    t.second = newRating;
    fd[food] = t;
  }

  string highestRated(string cuisine) {
    string ans;
    auto   t = ma[cuisine].rbegin();
    for (auto it = ma[cuisine].rbegin(); it != ma[cuisine].rend(); it++) {
      if (it->first == t->first) {
        ans = it->second;
      } else
        break;
    }
    return ans;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */