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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int group = 0;
        ListNode * ptrr = head;
        while(ptrr != nullptr && group < k){
            ptrr = ptrr->next;
            group++;
        }
        if(group == k){
            ptrr = reverseKGroup(ptrr, k);
            while(group-- > 0){
                ListNode * tmp = head->next;
                head->next = ptrr;
                ptrr = head;
                head = tmp;
            }
            head = ptrr;
        }
    return head;
    }

};
