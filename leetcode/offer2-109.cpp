/*
 *@File Name          :offer2-109.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 19:41
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "queue"
#include "set"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    queue<pair<string, int>> que;
    que.push({"0000", 0});

    auto next_ch = [](char ch) -> char { return (ch - '0' + 1) % 10 + '0'; };
    auto pre_ch  = [](char ch) -> char {
      return (ch - '0' - 1 + 10) % 10 + '0';
    };

    set<string> se;
    for (auto& x : deadends) se.insert(x);
    if (se.count("0000")) return -1;
    se.insert("0000");
    while (!que.empty()) {
      auto q = que.front();
      que.pop();
      if (q.first == target) return q.second;
      for (int i = 0; i < 4; i++) {
        char ch    = q.first[i];
        q.first[i] = next_ch(ch);
        if (!se.count(q.first)) {
          se.insert(q.first);
          que.push({q.first, q.second + 1});
        }
        q.first[i] = pre_ch(ch);
        if (!se.count(q.first)) {
          se.insert(q.first);
          que.push({q.first, q.second + 1});
        }
        q.first[i] = ch;
      }
    }
    return -1;
  }
};