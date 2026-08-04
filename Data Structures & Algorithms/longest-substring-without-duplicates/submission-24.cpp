class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int res = 0;
        while(r < s.size()){
            if(mp.count(s[r])){
                l = max(l, mp[s[r]]+1);

            }
            mp[s[r]] = r;
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
