/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        auto slow = head;
        auto fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        auto sec = slow->next;
        ListNode * prev = nullptr;
        slow->next = nullptr;
        while(sec){
            auto tmp = sec->next;
            sec->next = prev;
            prev = sec;
            sec = tmp;
        }
        auto first = head;
        sec = prev;
        while(sec){
            auto tmp1 = first->next;
            auto tmp2 = sec->next;
            first->next = sec;
            sec->next = tmp1;
            first = tmp1;
            sec = tmp2;
        }
    }
};
