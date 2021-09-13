#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lena, lenb;
        lena = nums1.size();
        lenb = nums2.size();
        if(lena > lenb)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = lena*2;
        int l1, l2, r1, r2, mc, c;

        while(l <= r){
            mc = (l+r)>>1;
            c = lena+lenb-mc;
            if(mc == 0)
                l1 = INT_MIN;
            else l1 = nums1[(mc-1)/2];
            if(mc == 2*lena)
                r1 = INT_MAX;
            else r1 = nums1[mc/2];
            if(c == 0)
                l2 = INT_MIN;
            else l2 = nums2[(c-1)/2];
            if(c == 2*lenb)
                r2 = INT_MAX;
            else r2 = nums2[c/2];
            if(l1 > r2)
                r = mc-1;
            else if(l2 > r1)
                l = mc+1;
            else break;
        }
        return (max(l1, l2)+min(r1, r2))/2.0;
    }
};

int main(){
    Solution s;
    vector<int> a = {1,3};
    vector<int> b = {2};
    printf("%f\n",s.findMedianSortedArrays(a, b));
    return  0;
}
