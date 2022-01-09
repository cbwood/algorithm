/*
 * @File Name          :leetcode-141.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/7 9:22
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include <cstddef>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode* slow = head, *fast = head->next;
        while (slow != nullptr && fast!= nullptr&& slow != fast){
            slow = slow->next;
            if(fast->next != nullptr)
                fast = fast->next->next;
            else fast = nullptr;
        }return slow == fast;
    }
};