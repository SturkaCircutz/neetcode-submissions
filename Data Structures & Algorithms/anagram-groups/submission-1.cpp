class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> pool(strs.size(), true);
        for(int i = 0; i < strs.size(); ++i){
            vector<string> temp;
            if(pool[i])
            temp.push_back(strs[i]);
            else continue;
            for(int j = i+1; j < strs.size(); ++j){
                if(strs.empty()) return ans;
                if(issame(strs[j], strs[i]) && pool[j]){
                    temp.push_back(strs[j]);
                    pool[j]=false;
                }
            }
            ans.push_back(temp); 
        }
        return ans;
    }

    bool issame(string &a, string &b){
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        if (a.size()!=b.size()) return false;
        for(auto cha:a){
            mp1[cha]++;
        }
        for(auto cha:b){
            mp2[cha]++;
        }
        if(mp1 == mp2) return true;
        return false;

    }
};
