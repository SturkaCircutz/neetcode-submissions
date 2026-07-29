class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(auto s : strs){
            unordered_map<int, int> count;
            for(auto c : s){
                count[c-'a']++;
            }
            string key;
            for(int c = 0; c < 26; c++){
                key += "," + to_string(count[c]);
            }
            mp[key].push_back(s);
        }
        for(auto i : mp){
            res.push_back(i.second);
        }
        return res;
    }
};
