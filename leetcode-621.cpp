#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int nums[30];
        int flag[30];
        for(int i = 0; i < 27; ++i)
            nums[i] = 0,flag[i] = -1000;
        for(auto &x: tasks)
            nums[x-'A']++;
        int ans = 0;
        int lenq = tasks.size();
        while(true){
            bool check = true;
            int maxi = 0, k=-1;
            for(int i = 0; i < 26; ++i){
                if(nums[i]>maxi&&ans-flag[i]>=n){
                    k = i;
                    maxi = nums[i];
                    check = false;
                }
            }if(check){
                if(!lenq)
                    break;
                ans++;
            }else{
                lenq--;
                ans++;
                flag[k] = ans;
                nums[k]--;
            }
        }return ans;
    }
};


int main(){
    Solution so;
    vector<char> tasks{'A','A','A','B','B','B'};
    printf("%d\n", so.leastInterval(tasks, 2));
    return 0;
}