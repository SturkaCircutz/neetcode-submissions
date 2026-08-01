class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int count = 0;
        int res = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            count = max(mp[s[i]], count);
            while(i - l +1 - count > k){
                mp[s[l]]--;
                l++;
            }
            res = max( res, i -l +1);
        }
        return res;
    }
};
