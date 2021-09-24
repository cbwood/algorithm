//
// Created by cb on 2021/9/23.
//

#include "vector"
#include "algorithm"
#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int numab[2] = {0, 0};
        for (auto &x: pattern)
            numab[x - 'a']++;
        if(value.empty()){
            if(numab[0]==0||numab[1] == 0)
                return true;
            return false;
        }
        return dfs(pattern, value, 0, 0, "-1", "-1", numab);
    }

    bool dfs(string &p, string &v, int kp, int kv, string a, string b, int numab[]) {
        if (kv == v.size() && kp == p.size()) return true;
        if(kv > v.size()) return false;
        if(kp >= p.size()) return false;
        int lenb = b.size(), lena = a.size();
        if (b == "-1") lenb = 0;
        if (a == "-1") lena = 0;
        if (p[kp] == 'a') {
            if (a == "-1") {
                if (dfs(p, v, kp + 1, kv, "", b, numab)) return true;
                a = "";
                for (int i = kv; i < v.size(); i++) {
                    lena++;
                    a += v[i];
                    if (lena * numab[0] + lenb * numab[1] > v.size()) break;
                    if(a == b) return false;
                    if (dfs(p, v, kp + 1, i + 1, a, b, numab)) return true;
                }
            } else {
                string tmp = v.substr(kv, a.size());
                if (tmp != a) return false;
                if (dfs(p, v, kp + 1, kv + a.size(), a, b, numab)) return true;
            }
        } else {
            if (b == "-1") {
                if (dfs(p, v, kp + 1, kv, a, "", numab)) return true;
                b = "";
                for (int i = kv; i < v.size(); i++) {
                    lenb++;
                    b += v[i];
                    if (lena * numab[0] + lenb * numab[1] > v.size()) break;
                    if(a == b) return false;
                    if (dfs(p, v, kp + 1, i + 1, a, b, numab)) return true;
                }
            } else {
                string tmp = v.substr(kv, b.size());
                if (tmp != b) return false;
                if (dfs(p, v, kp + 1, kv + b.size(), a, b, numab)) return true;
            }
        }
        return false;
    }
};