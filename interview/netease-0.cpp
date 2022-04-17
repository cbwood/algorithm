/*
 *@File Name          :netease-0.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/17 14:58
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class team {
public:
    int point, in, loss;
    int num;
    string name;

    bool operator<(const team &q) {
        if (q.point == point) {
            if (num == q.num) {
                if (in == q.in) {
                    return name < q.name;
                }
                return in > q.in;
            }
            return num > q.num;
        }
        return point > q.point;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<team> a(6);
        int n = 9;
        for (int i = 0; i < 6; i++) {
            cin >> a[i].name >> a[i].point >> a[i].in >> a[i].loss;
            a[i].num = a[i].in - a[i].loss;
        }
        for (int i = 0; i < 3; i++) {
            string name1, name2;
            int in1, in2;
            cin >> name1 >> name2 >> in1 >> in2;
            if (in1 < in2) {
                swap(name1, name2);
                swap(in1, in2);
            }
            int p = 3;
            if (in1 == in2)
                p = 1;
            for (int j = 0; j < 6; j++) {
                if (a[j].name == name1) {
                    a[j].point += p;
                    a[j].in += in1;
                    a[j].loss += in2;
                    a[j].num = a[j].in - a[j].loss;
                }
            }
            p = 0;
            if (in1 == in2)
                p = 1;
            for (int j = 0; j < 6; j++) {
                if (a[j].name == name2) {
                    a[j].point += p;
                    a[j].in += in2;
                    a[j].loss += in1;
                    a[j].num = a[j].in - a[j].loss;
                }
            }
        }
        std::sort(a.begin(), a.end());
        for (int i = 0; i < 6; i++) {
            cout << a[i].name << " " << a[i].point << " " << a[i].in << " " << a[i].loss << endl;
        }
        cout << "END" << endl;
    }
    return 0;
}