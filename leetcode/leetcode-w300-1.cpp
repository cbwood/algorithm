/*
 *@File Name          :leetocde-w300-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/3 10:43
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  string decodeMessage(string key, string message) {
    vector<char>   v;
    map<char, int> ma;
    set<char>      se;
    se.insert(' ');
    for (auto k : key) {
      if (se.count(k) == 0) {
        v.push_back(k);
        ma[k] = v.size() - 1;
        se.insert(k);
      }
      if (se.size() == 26) break;
    }
    cout << ma['o'] << endl;
    for (int i = 0; i < message.size(); i++) {
      if (message[i] == ' ') continue;
      message[i] = ma[message[i]] + 'a';
    }
    return message;
  }
};