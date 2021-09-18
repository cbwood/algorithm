//
// Created by cb on 2021/9/18.
//

#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int k = 30;
        string ans = "";
        while (k > 0 && num < a[k]) k--;
        if (a[k] <= 90) {
            ans += b[k];
        } else {
            ans += numberToWords(num / a[k]) + " " + b[k];
        }
        if (num % a[k])ans += " " + numberToWords(num % a[k]);
        return ans;
    }

private:
    const int a[31] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80,
                       90, 100, 1000, 1000000, 1000000000};
    const string b[31] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                          "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
                          "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred",
                          "Thousand", "Million", "Billion"};
};
