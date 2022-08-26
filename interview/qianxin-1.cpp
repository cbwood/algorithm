/*
*@File Name          :qianxin-1.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/25 19:28
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
    * 计算dag 路径上起始到目的节点的路径数目
    * @param nodes int整型vector<vector<>> 第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ），若为空，就是没有下一个节点了。
    * @return int整型
    */
  int DagPathNum(vector<vector<int> >& nodes) {
    // write code here
    ans = 0;
    dfs(nodes, 0);
    return ans;
  }

  int ans;

  void dfs(vector<vector<int> >& nodes, int cur) {
    if (cur == nodes.size() - 1) {
      ans++;
      return;
    }
    for (auto& x : nodes[cur]) { dfs(nodes, x); }
  }
};