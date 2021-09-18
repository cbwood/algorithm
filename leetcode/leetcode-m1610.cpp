    //
    // Created by cb on 2021/9/18.
    //

    #include "vector"
    #include "algorithm"
    #include "map"

    using namespace std;

    class Solution {
    public:
        int maxAliveYear(vector<int> &birth, vector<int> &death) {
            vector<int>b(102);
            for(auto &x: birth)
                b[x-1900]++;
            for(auto &x: death)
                b[x-1900+1]++;
            int ans = 1900, sumx = 0, tmpsum = -1;
            for(int i = 1900; i <= 2000; i++){
                sumx += b[i-1900];
                if(sumx > tmpsum){
                    tmpsum = sumx;
                    ans = i;
                }
            }
            return ans;
        }
    };
