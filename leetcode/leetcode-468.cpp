/*
 *@File Name          :leetcode-468.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/30 9:31
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  bool checkIPV4(string queryIP) {
    int nums = -1;
    int k    = 0;
    if (queryIP.empty() || queryIP[0] == '.') return false;
    for (auto& x : queryIP) {
      if (x == '.') {
        if (nums > 255 || nums < 0) return false;
        nums = -1;
        k++;
        if (k > 3) return false;
      } else if (isdigit(x)) {
        if (nums == -1)
          nums = x - '0';
        else {
          if (nums == 0) return false;
          nums = nums * 10 + (x - '0');
          if (nums == 0 || nums > 255) return false;
        }
      } else
        return false;
    }
    return nums != -1 && k == 3;
  }

  bool checkIPV6(string queryIP) {
    int nums = 0;
    int k    = 0;
    for (auto& x : queryIP) {
      if (x == ':') {
        if (nums == 0 || nums > 4) return false;
        nums = 0;
        k++;
        if (k > 7) return false;
      } else if (isdigit(x) || (x >= 'a' && x <= 'f') ||
                 (x >= 'A' && x <= 'F')) {
        nums++;
      } else
        return false;
    }
    return nums > 0 && nums <= 4 && k == 7;
  }

  string validIPAddress(string queryIP) {
    if (checkIPV4(queryIP)) return "IPv4";
    if (checkIPV6(queryIP)) return "IPv6";
    return "Neither";
  }
};