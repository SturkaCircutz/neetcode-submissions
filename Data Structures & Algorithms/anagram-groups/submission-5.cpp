class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anag;
        for(auto str : strs){
            unordered_map<int, int> mp;
            for(auto c : str){
                mp[c-'a']++;
            }
            string key;
            for(int i = 0; i < 26; i++){
                key += ','+mp[i];
            }
            anag[key].push_back(str);
        }
        for(auto i : anag){
            res.push_back(i.second);
        }
        return res;
    }
};
