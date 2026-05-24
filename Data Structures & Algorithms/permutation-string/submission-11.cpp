class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        unordered_map<char, int> mp;
        for(auto s:s1){
            mp[s]++;
        }
        int l =0;
        unordered_map<char, int> tmp;
        for(int r = 0; r < s2.length();++r){
            tmp[s2[r]]++;
            if(r-l+1>s1.length()){
                tmp[s2[l]]--;
                if(tmp[s2[l]]==0){
                tmp.erase(s2[l]);
                }
                l++;
            }
            if(tmp==mp) return true;
        
            
        }
        return false;
    }
};
