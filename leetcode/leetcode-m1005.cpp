//
// Created by cb on 2021/9/17.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int findString(vector<string> &words, string s) {
        int l = 0, r = words.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            while (mid > l && words[mid] == "") mid--;
            if (words[mid] == s) return mid;
            if (words[mid] > s) r = mid - 1;
            if (words[mid] < s) l = mid + 1;
        }
        return -1;
    }
};


int main() {
    return 0;
}