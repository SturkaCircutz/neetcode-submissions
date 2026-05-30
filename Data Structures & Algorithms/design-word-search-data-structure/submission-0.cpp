class TrieNode{
    public:
        TrieNode * tmp[26];
        bool isend = false;
        TrieNode(){
        for(int i =0; i<26; ++i){
            tmp[i]=nullptr;
            }
        }
};
class WordDictionary {
public:
    TrieNode * root = new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode * ptr = root;
        for(auto & w : word){
            int idx = w - 'a';
            if(ptr->tmp[idx]==nullptr){
                ptr->tmp[idx]=new TrieNode();
            }
            ptr = ptr->tmp[idx];
        }
        ptr->isend = true;
        return;
        
    }
    bool dfs(string word, int pos, TrieNode * ptr){
        if(ptr == nullptr) return false;
        if(pos == word.length()) return ptr->isend;
        char w = word[pos];
        if(w != '.'){
            return dfs(word, pos+1, ptr->tmp[w-'a']);
        }
        for(int i = 0; i < 26; ++i){
            if(ptr->tmp[i] && dfs(word, pos+1, ptr->tmp[i])){
                return true;
            }
        }
        return false;
    }
    bool search(string word) {  
        return dfs(word, 0, root);
    }
};
