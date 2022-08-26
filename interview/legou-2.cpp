/*
*@File Name          :legou-2.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/20 20:48
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  /**
    * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
    *
    * 给定字符串 和 显示宽度。 按规则返回自动换行处理后的最后一行。 如不能则返回字符串"error"
    * @param str string字符串 给定的字符串
    * @param width int整型 显示的宽度
    * @return string字符串
    */
  string getLastLine(string str, int width) {
    // write code here
    int    n    = str.size();
    int    base = 16;
    int    k    = 0;
    string nums = "";
    while (k < n && str[k] == ' ') nums.push_back(' '), k++;
    if (nums.size() * base >= width) nums = "";
    int    pre = -1;
    string ans = "";
    for (int i = k; i < n; i++) {
      nums.push_back(str[i]);
      if (str[i] == ' ') pre = nums.size();
      if (str[i] == '\n') nums = "";
      if (nums.size() * base > width) {
        if (pre == -1) return "error";
        if (pre == nums.size()) {
          int ti = i + 1;
          while (str[ti] == ' ') {
            nums.push_back(' ');
            ti++;
            pre++;
          }
          i = ti - 1;
        }
        ans  = nums.substr(0, pre);
        nums = nums.substr(pre, nums.size() - pre + 1);
        pre  = -1;
      }
    }
    if (nums.empty()) return ans;
    return nums;
  }
};
