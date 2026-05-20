class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int left = 0, right = 1;
        int maxi =1;
        unordered_map<char, int> mp;
        mp[s[left]]++;
        while(right<s.length()){
            if(mp.find(s[right])==mp.end()){
                maxi = max(maxi, right-left+1);
                mp[s[right]]++;
                right++;
            }
            else{
                left ++;
                mp.clear();
                mp[s[left]]++;
                right = left +1;
            }
        }
        return maxi;
    }
};
