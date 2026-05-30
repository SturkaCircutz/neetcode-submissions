class LRUCache {
public:
    int CAP;
    vector<pair<int, int>> lru;
    LRUCache(int capacity) {
        CAP = capacity;

    }
    
    int get(int key) {
        for(int i = 0; i<lru.size(); ++i){
            if(lru[i].first == key){
                pair<int, int> tmp = lru[i];
                lru.erase(lru.begin()+i);
                lru.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i < lru.size(); ++i){
            if(lru[i].first==key){
                lru.erase(lru.begin()+i);
                lru.push_back({key, value});
                return;
            }
        }
        if(lru.size()<CAP)
        lru.push_back({key, value});
        else{
            lru.erase(lru.begin());
            lru.push_back({key, value});
        }
    }
};
