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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2==nullptr) return nullptr;
        if(list1 != nullptr && list2 == nullptr) return list1;
        if(list2 != nullptr && list1 == nullptr ) return list2;
        ListNode * head = new ListNode();
        ListNode * res = head;
        ListNode * l1head = list1;
        ListNode * l2head = list2;
        while(l1head != nullptr && l2head != nullptr){
        if(l1head->val < l2head->val){
            head->next = l1head;
            l1head = l1head->next;
            head=head->next;
        }else{
            head->next = l2head;
            l2head = l2head->next;
            head=head->next;
        }
        if(l1head != nullptr) head->next = l1head;
        }
        if(l2head != nullptr) head->next = l2head;
        return res->next;
    }
};
