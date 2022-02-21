#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:

    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i = 2; i <= n; i++){
            string tmp = to_string(i);
            ans.emplace_back("1/"+tmp);
            for(int j = 2; j < i; j++){
                if(gcd(i,j) == 1)
                    ans.emplace_back(to_string(j)+"/"+tmp);
            }
        }return ans;
    }
};