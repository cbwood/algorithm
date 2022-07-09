/*
 *@File Name          :shein-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/7 15:19
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "map"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param haystack string字符串
     * @param needle string字符串
     * @return int整型
     */
  int strStr(string haystack, string needle) {
    // write code here
    int         len1 = haystack.size();
    int         len2 = needle.size();
    vector<int> next(len2 + 1, 0);
    int         i = 0, j = -1;
    next[0] = -1;
    while (i < len2) {
      if (j == -1 || needle[i] == needle[j])
        next[++i] = next[++j] + 1;
      else
        j = next[j];
    }

    i = 0;
    j = 0;
    while (i < len1 && j < len2) {
      if (j == -1 || haystack[i] == needle[j])
        i++, j++;
      else
        j == next[j];
    }
    if (j == len2) return i - j;
    return -1;
  }
};