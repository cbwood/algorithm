#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        map<char, int> ma;
        for(auto &x:astr){
            ma[x]++;
            if(ma[x] > 1) return false;
        }return true;
    }
};

int main(){
    return 0; 
}