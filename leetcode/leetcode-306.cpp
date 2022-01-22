/*
 * @File Name          :leetcode-306.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/10 9:06
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "string"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        long long  a = 0, b = 0;
        for (int i = 0; i < n/3+1; i++) {
            a = a * 10 + num[i] - '0';
            b = 0;
            for (int j = i + 1; j < 2*n/3 + 2; j++) {
                b = b * 10 + num[j] - '0';
                if (j <= n-2 && dfs(a, b, num, j + 1)) return true;
                if(num[i+1] == '0') break;
            }if(a == 0) break;
        }
        return false;
    }

    bool dfs(long long a, long long b, string &num, int k) {
        if (k == num.size()) return true;
        if (k > num.size()) return false;
        long long ab = a + b;
        long long t = 0;
        for (int i = k; i < num.size(); i++) {
            t = t * 10 + num[i] - '0';
            if (t == ab) {
                if (dfs(b, ab, num, i + 1)) return true;
                break;
            } else if (t > ab) return false;
            if(num[k] == '0') break;
        }
        return false;
    }
};