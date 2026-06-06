class Solution {
public:
    unordered_map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()] = true;
        return dfs(s, wordDict, 0);
    }
    bool dfs(string s, vector<string> & wordDict, int i){
        if(memo.find(i)!=memo.end()) return memo[i];
        for(int j = 0; j<wordDict.size(); j++){
            int ws = wordDict[j].size();
            if(i+ws <= s.length() && s.substr(i, ws) == wordDict[j]){
                if(dfs(s, wordDict, i+ws)){
                    memo[i]=true;
                    return true;
                }

            }

            
        }
        memo[i]=false;
        return false;
    }
};
