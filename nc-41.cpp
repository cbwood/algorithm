#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        int n = arr.size();
        int l=0;
        int ans=0;
        map<int, int> ma;
        for(int i = 0;i < n; i++){
            ma[arr[i]]++;
            while(ma[arr[i]]>1 && l<i) ma[arr[l++]]--; 
            ans = max(ans, i-l+1);
        }return ans;
    }
};

int main(){

    return 0;
}