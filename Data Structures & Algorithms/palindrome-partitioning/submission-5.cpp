class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        dfs(s, res, curr, 0);
        return res;
    }
    void dfs(string s, vector<vector<string>>&res, vector<string>&curr, int i){
        if(i>=s.length()){
            res.push_back(curr);
            return;
        }
        for(int j = i; j < s.length(); j++){
            if(ispali(s, i, j)){
                curr.push_back(s.substr(i, j-i+1));
                dfs(s, res, curr, j+1);
                curr.pop_back();
            }
        }
    }
    bool ispali(string s, int i, int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
