class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r= 0;
        int res = 0;
        int maxlen = 0;
        unordered_map<char, int> mp;
        while(r < s.size()){
            mp[s[r]]++;
            maxlen = max(maxlen, mp[s[r]]);
            if(r-l+1-maxlen > k){
                mp[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
