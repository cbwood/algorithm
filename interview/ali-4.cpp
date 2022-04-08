/*
 *@File Name          :ali-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/7 19:24
 *@Description        :统计账单
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

double string2int(string s) {
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ':') {
            pos = i + 1;
            break;
        }
    }
    int flag = 1;
    if (s[pos] == '-') {
        flag = -1;
        pos++;
    } else if (s[pos] == '+') {
        pos++;
    }
    double ans = 0;
    for (int i = pos; i < s.size(); i++) {
        if (s[i] == '.') {
            pos = i + 1;
            break;
        }
        ans = ans * 10 + s[i] - '0';

    }
    double tt = 1.0 * ((s[pos] - '0') * 10 + s[pos + 1] - '0') / 100;
    return (ans + tt) * flag;
}

int string2m(string s) {
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ':') {
            pos = i + 1;
            break;
        }
    }
    int ans = 0;
    for (int i = pos; i < s.size(); i++) {
        ans = ans * 10 + s[i] - '0';

    }
    return ans;
}

int main() {
    map<string, double> ma;
    vector<double> out(12, 0), in(12, 0);
    vector<string> month{"January", "February", "March", "April", "May", "June", "July", "August", "September",
                         "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        int m = string2m(s);
        while (m--) {
            cin >> s;
            double k = string2int(s);
//            cout<<s<<" "<<k<<endl;
            ma[month[i]] += k;
            if (k >= 0)
                in[i] += k;
            else out[i] += k;
        }
    }
    int minx = 0, maxx = 0;
    for (int i = 0; i < 12; i++) {
        cout << month[i] << ":";
        if (ma[month[i]] >= 0)
            cout << "+";
        printf("%.2f\n", ma[month[i]]);
        if (in[i] > in[maxx]) {
            maxx = i;
        }
        if (out[i] < out[minx]) {
            minx = i;
        }
    }
    cout << month[minx] << " " << month[maxx] << endl;
    return 0;
}

/*
 * January:+930.50
February:+550.55
March:+100.50
April:+811.11
May:-1024.00
June:+100.00
July:+100.50
August:+100.50
September:+100.50
October:+100.50
November:+100.50
December:+100.50
May January
 */