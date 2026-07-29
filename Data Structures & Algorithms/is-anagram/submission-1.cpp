class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        if (s.length() != t.length()) return false;
        for(auto c : s){
            mp[c]++;
        }
        for(auto c: t){
            mp1[c]++;
        }
        if(mp == mp1) return true;
        return false;
    }
};
