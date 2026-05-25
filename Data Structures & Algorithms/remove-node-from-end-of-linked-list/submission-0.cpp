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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * temp = head;
        int count = 0;
        ListNode * prev = nullptr;
        int total = 0;
        ListNode * co = head;
        while(co!=nullptr){
            total++;
            co=co->next;
        }
        total = total - n+1; //
        while(temp!=nullptr){
            count ++;
            if(count==total){
                if(prev!=nullptr)
                {
                prev->next = temp->next;
                return head;
                }
                return head->next; //
 
            }
            prev = temp; //
            temp = temp->next;
        }
        return head;
    }
};
