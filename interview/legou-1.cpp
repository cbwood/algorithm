/*
 *@File Name          :legou-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/20 20:34
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
     * 输入参数 Ax 角色A的血量，Ay 角色A 的攻击力，Az A的攻击CD，Aw 角色A的恢复力
输入参数 Bx 角色B的血量，By 角色B 的攻击力，Bz B的攻击CD，Bw 角色B的恢复力
     * @param Ax int整型 角色A的血量上限
     * @param Ay int整型 角色A的攻击力
     * @param Az int整型 A的攻击CD
     * @param Aw int整型 角色A的每回合恢复血量值
     * @param Bx int整型 角色B的血量上限
     * @param By int整型 角色B的攻击力
     * @param Bz int整型 B的攻击CD
     * @param Bw int整型 角色B的每回合恢复血量值
     * @return int整型
     */
  int PK(int Ax, int Ay, int Az, int Aw, int Bx, int By, int Bz, int Bw) {
    // write code here
    int k = 0;
    Az++;
    Bz++;
    int maxa = Ax;
    int maxb = Bx;
    if (By <= Aw * Bz && Ay <= Bw * Az) return 4;
    while (Ax >= 0 && Bx >= 0) {
      if (k % Az == 0) Bx -= Ay;
      if (k % Bz == 0) Ax -= By;
      if (Ax >= 0) Ax += Aw;
      if (Bx >= 0) Bx += Bw;
      if (Ax > maxa) Ax = maxa;
      if (Bx > maxb) Bx = maxb;
      k++;
    }
    if (Ax <= 0 && Bx <= 0) return 3;
    if (Ax <= 0) return 2;
    return 1;
  }
};