class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int maxi = 1;
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        while(r < s.size()){
            if(mp.find(s[r])!=mp.end()){
                l = max(l, mp[s[r]]+1);
            }
            mp[s[r]] = r;
            maxi = max(maxi, r - l+1);
            r++;
        }
        return maxi;
    }
};
