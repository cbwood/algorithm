#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size()-1;
        while(l < r){
            ans = max(ans, (r-l)*(min(height[l], height[r])));
            if(height[l] < height[r])
                l++;
            else r--;
        }return ans;
    }
};

int main(){
    vector<int> v;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }
    Solution so;
    cout << so.maxArea(v) << endl;
    return 0;
}