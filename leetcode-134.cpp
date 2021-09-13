#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = -1;
        int minans = 10000000;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += gas[i]-cost[i];
            if(sum < minans){
                minans = sum;
                ans = i;
            }
        }return sum < 0? -1: (ans+1)%n;
    }
};