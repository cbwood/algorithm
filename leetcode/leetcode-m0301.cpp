//
// Created by cb on 2021/9/13.
//
#include "vector"
#include "cmath"
using namespace std;

class TripleInOne {
public:
    std::vector<int> stac;
    TripleInOne(int stackSize) {
        stac = std::vector<int>(3*(stackSize+1), 0);
    }

    void push(int stackNum, int value) {
        if(stac[stackNum]*3+ 3 >= stac.size()) return;
        stac[stackNum]++;
        stac[stac[stackNum]*3+stackNum] = value;
    }

    int pop(int stackNum) {
        if(stac[stackNum] == 0) return -1;
        stac[stackNum] = max(stac[stackNum]-1, 0);
        return stac[(stac[stackNum]+1)*3+stackNum];
    }

    int peek(int stackNum) {
        if(stac[stackNum] == 0) return -1;
        return stac[stac[stackNum]*3+stackNum];
    }

    bool isEmpty(int stackNum) {
        return stac[stackNum] == 0;
    }
};

int main() {

    return 0;
}