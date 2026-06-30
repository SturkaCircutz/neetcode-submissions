/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node *,Node*> mp;
    Node* copyRandomList(Node* head ) {
        if(head == nullptr) return nullptr;
        if(mp.count(head)) return mp[head];
        Node * cp = new Node(head->val);
        mp[head] = cp;
        cp->next = copyRandomList(head->next);
        cp->random = mp[head->random];
        return cp;
    }
};
