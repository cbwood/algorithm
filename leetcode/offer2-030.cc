/*
 *@File Name          :offer2-030.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/28 9:23
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "map"
#include "unordered_map"

using namespace std;


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(nullptr));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (ma.find(val) != ma.end())
            return false;
        ma[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (ma.find(val) == ma.end())
            return false;
        nums[ma[val]] = nums.back();
        ma[nums.back()] = ma[val];
        nums.pop_back();
        ma.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int n = random() % nums.size();
        return nums[n];
    }

private:
    vector<int> nums;
    unordered_map<int, int> ma;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */