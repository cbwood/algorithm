/*
 *@File Name          :leetcode-165.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/11 9:23
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int conert(const string& s, int& i) {
    int k = i;
    if (k >= s.size()) return 0;
    while (k < s.size()) {
      if (s[k] == '.') break;
      k++;
    }
    int num = stoi(s.substr(i, k - i));
    i       = k + 1;
    return num;
  }

  int compareVersion(string version1, string version2) {
    int len1 = version1.size();
    int len2 = version2.size();
    int i    = 0;
    int j    = 0;
    while (i < len1 || j < len2) {
      int k1 = conert(version1, i);
      int k2 = conert(version2, j);
      if (k1 < k2) return -1;
      if (k1 > k2) return 1;
    }
    return 0;
  }
};