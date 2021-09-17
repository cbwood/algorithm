//
// Created by cb on 2021/9/16.
//

#include "algorithm"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int search(vector<int> &arr, int target) {
        int ans = -1;
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
//            if (arr[mid] == target) ans = mid;
            if (arr[l] < arr[mid]) {
                if (arr[mid] >= target && target>= arr[l])
                    r = mid - 1;
                else l = mid + 1;
            } else if(arr[l] > arr[mid]){
                if (arr[mid] <= target && target <= arr[r])
                    l = mid + 1;
                else r = mid - 1;
            }else if(arr[l] == arr[mid]){
                if(arr[l] != target)
                    l++;
                else r = l;
            }
        }
        return arr[l] == target ? l: -1;
    }
};

int main() {
    vector<int> a{12, 20, -21, -21, -19, -14, -11, -8, -8, -8, -6, -6, -4, -4, 0, 1, 5, 5, 6, 11, 11, 12};
    Solution so;
    cout<<so.search(a, -8);
    return 0;
}
