/*
 *@File Name          :offer2-108.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 19:04
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "iostream"
#include "map"
#include "queue"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    map<string, int> ma;
    ma[beginWord] = 1;
    int cnt       = 2;
    for (auto& x : wordList) ma[x] = cnt++;

    if (ma[endWord] == 0) return 0;

    map<int, vector<int>> e;
    wordList.push_back(beginWord);
    for (auto x : wordList) {
      int k = ma[x];
      for (int i = 0; i < x.size(); i++) {
        char ch = x[i];
        x[i]    = '*';
        if (!ma[x]) ma[x] = cnt++;
        e[k].push_back(ma[x]);
        e[ma[x]].push_back(k);
        x[i] = ch;
      }
    }

    queue<pair<int, int>> que;
    que.push({ma[beginWord], 0});
    vector<bool> vis(cnt, false);
    vis[1] = true;

    while (!que.empty()) {
      auto q = que.front();
      que.pop();
      if (q.first == ma[endWord]) return q.second / 2 + 1;
      for (auto& x : e[q.first]) {
        if (!vis[x]) {
          vis[x] = true;
          que.push({x, q.second + 1});
        }
      }
    }
    return 0;
  }
};

int main() {
  Solution so;
  cout << so.ladderLength(
              "hit", "cog",
              vector<string>{"hot", "dot", "dog", "lot", "log", "cog"})
       << endl;
  return 0;
}