class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> ans(n+1);
        ans[0].push_back("");
        for(int i = 0; i<=n; ++i){
            for(int j = 0; j < i; ++j){
                for(auto s: ans[j]){
                    for(auto k: ans[i-j-1]){
                        ans[i].push_back("("+s+")"+k);
                    }
                }
            }
        }
        return ans[n];
    }
};
