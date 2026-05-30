class TrieNode{
    public:
        TrieNode* child[26];
        bool isend;
        TrieNode(){
            isend = false;
            for(int i =0; i<26; ++i){
                child[i] = nullptr;
            }
        }
};

class PrefixTree {
public:
    TrieNode * root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(char c:word){
            int idx  = c-'a';
            if(node->child[idx] == nullptr){
                node->child[idx]= new TrieNode(); // we need a new node of 26 pointers since each node could have up to 26 child
            }
            node = node->child[idx];
        }
        node->isend = true;
    }
    
    bool search(string word) {
        TrieNode * node = root;
        for(char c : word){
            int idx = c-'a';
            if(node->child[idx]==nullptr){
                return false;
            }
            node = node->child[idx];
        }
         return node->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode * node = root;
        for(char c : prefix){
            int idx = c-'a';
            if(node->child[idx]==nullptr){
                return false;
            }
            node = node->child[idx];
        }
         return true;
    }
};
