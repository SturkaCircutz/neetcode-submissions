class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int count = 0;
        while(r < s.size()){
            
            unordered_set<char> mp;
            int localcount = 0;
            while(!mp.count(s[r]) && r < s.size()){
                mp.insert(s[r]);
                r++;
                localcount++;
            }   
            count = max(localcount, count);
            l++;
            r = l;

        }
        return count;
    }
};
