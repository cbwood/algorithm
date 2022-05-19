/*
 *@File Name          :offer2-057.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/18 8:26
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "climits"

using namespace std;

//class Solution {
//public:
//    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//        int n = nums.size();
//        multiset<int> mse;
//        for(int i = 0; i < n; i++){
//            auto iter = mse.lower_bound(max(nums[i], INT_MIN+t)-t);
//            if(iter != mse.end() && *iter <= min(INT_MAX-t, nums[i])+t)
//                return true;
//            mse.insert(nums[i]);
//            if( i >= k){
//                mse.erase(nums[i-k]);
//            }
//        }
//        return false;
//    }
//};

class Solution {
public:
    int get_id(int x, long long w) {
        return x < 0 ? (x + 1) / w - 1 : x / w;
    }

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        int n = nums.size();
        map<int, long long> ma;
        for (int i = 0; i < n; i++) {
            int id = get_id(nums[i], t + 1LL);
            if (ma.count(id)) {
                return true;
            }
            if (ma.count(id + 1) && ma[id + 1] - nums[i] <= t)
                return true;
            if (ma.count(id - 1) && nums[i] - ma[id - 1] <= t)
                return true;
            ma.insert({id, nums[i]});
            if (i >= k)
                ma.erase(get_id(nums[i - k], t + 1LL));
        }
        return false;
    }
};