#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int              val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a ListNode类 
     * @param b ListNode类 
     * @return ListNode类
     */
  ListNode* xorList(ListNode* a, ListNode* b) {
    // write code here
    int           maxn = 1e5 + 10;
    vector<short> dpa(maxn, 0);
    vector<short> dpb(maxn, 0);
    vector<short> dpc(maxn, 0);
    int           la = 0, lb = 0;
    while (a) {
      dpa[la++] = a->val;
      a         = a->next;
    }

    while (b) {
      dpb[lb++] = b->val;
      b         = b->next;
    }

    int ca = max(la, lb);

    for (int i = 0; i < ca; i++) { dpc[i] = dpa[i] ^ dpb[ca - i - 1]; }

    ListNode* ans = new ListNode(0);
    auto      t   = ans;
    int       c   = 0;
    while (c < ca) {
      if (dpc[c]) {
        while (c < ca) {
          t->next = new ListNode(dpc[c]);
          t       = t->next;
          c++;
        }
      }
      c++;
    }
    if(ans->next == nullptr) return ans;
    return ans->next;
  }
};

int main() { return 0; }