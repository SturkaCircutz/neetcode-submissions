class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> same;
        for(auto s : strs){
            vector<string> curr;
            string key;
            unordered_map<int, int>mp;
            for(auto c : s){
                mp[c-'a']++;
            }
            for(int i = 0; i < 26; i++){
                key+=','+to_string(mp[i]);
            }
            same[key].push_back(s);

        }
        for(auto s : same){
            res.push_back(s.second);
        }
        return res;
    }
};
