/*
 *@File Name          :offer2-058.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/19 10:30
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "map"

using namespace std;

class MyCalendar {
public:
    map<int, int> ma;

    MyCalendar() {
        ma[-1] = -1;
    }

    bool book(int start, int end) {
        auto it = ma.lower_bound(end);
        if ((--it)->second <= start) {
            ma[start] = end;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */