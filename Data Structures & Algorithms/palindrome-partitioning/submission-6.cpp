class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0, 0, s, part);
        return res;
    }
    void dfs(int j, int i, string s, vector<string> part){
        if(i >= s.size()){
            if(i == j) res.push_back(part);
            return;
        }
        
        if(parl(j, i, s)){
            part.push_back(s.substr(j, i-j+1));
            dfs(i+1, i+1, s, part);
            part.pop_back();

        }
        dfs(j, i+1, s, part);
    }
    bool parl(int x, int y, string s){
        while(x < y){
            if(s[x] != s[y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
};
