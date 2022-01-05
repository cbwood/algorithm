/*
 * @File Name          :leetcode-1576.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/5 9:01
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "string"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        int pre = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '?'){
                for(int j = 0; j < 24; j++){
                    if(j != pre&&(i>=s.size()-1||s[i+1]!=j+'a')){
                        s[i] = j+'a';
                        break;
                    }
                }
            }pre = s[i]-'a';
        }
        return s;
    }
};

int main(){
    Solution so;
    cout<<so.modifyString("ubv?w");
}