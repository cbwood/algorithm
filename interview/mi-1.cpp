#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

template <class Type> class ListNode {
 public:
  Type            data;
  ListNode<Type>* next;
};

class Solution {
 public:
  ListNode<int>* dfs(ListNode<int>* cur, ListNode<int>* pre, int l, int r) {
    if (l > r) return pre;
    if (cur == nullptr) return nullptr;
    auto t    = dfs(cur->next, cur, l + 1, r);
    cur->next = pre;
    return t;
  }

  /* Write Code Here */
  ListNode<int>* reverseBetween(ListNode<int>* head, int left, int right) {
    ListNode<int>* ans = new ListNode<int>();
    ans->next          = head;
    int            k   = 1;
    ListNode<int>* pre = nullptr;
    while (k < left && head) {
      pre = head;
      k++;
      head = head->next;
    }

    if(head == nullptr){
      return ans->next;
    }


    auto tail = head;
    while (k < right && tail) {
      k++;
      tail = tail->next;
    }
    if (tail)
      auto tmp = tail->next;
    else
      ListNode<int>* tmp = nullptr;
    auto t = dfs(head, tail->next, left, right);
    
    pre->next = t;
    return ans->next;
  }
};
int main() {
  ListNode<int>* res = NULL;

  int head_size = 0;
  cin >> head_size;

  ListNode<int>*head = NULL, *head_curr = NULL;
  int           head_item;
  for (int head_i = 0; head_i < head_size; head_i++) {
    cin >> head_item;

    ListNode<int>* head_temp = new ListNode<int>();
    head_temp->data          = head_item;
    head_temp->next          = NULL;
    if (head == NULL) {
      head = head_curr = head_temp;
    } else {
      head_curr->next = head_temp;
      head_curr       = head_temp;
    }
  }

  int left;
  cin >> left;

  int right;
  cin >> right;

  Solution* s = new Solution();
  res         = s->reverseBetween(head, left, right);
  while (res != NULL) {
    cout << res->data << " ";
    res = res->next;
  }
  cout << endl;

  return 0;
}
