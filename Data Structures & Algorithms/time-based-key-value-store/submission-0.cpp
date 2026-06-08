class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<int,string>>> mp;
    unordered_map<string, int> time;
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        int left = 0, right = mp[key].size()-1;
        string ans = "";
        while(left <= right){
            int mid = (left+right)/2;
            if(mp[key][mid].first<=timestamp){
                ans = mp[key][mid].second;
                left = mid +1;
            }
            else{
                right = mid -1;
            }
        }
        return ans;
    }
};
