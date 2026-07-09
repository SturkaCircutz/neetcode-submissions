class Solution {
public:
    vector<string> res;
    vector<string> mp = {
            "","","abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        trace("", res, 0, digits);
        return res;
    }

    void trace(string curr, vector<string>& res, int i, string digits){
        if(curr.size() == digits.size()){
            res.push_back(curr);
            return;
        }
        string num = mp[digits[i]-'0'];
        for(char & c : num){
            trace(curr+c, res, i+1, digits);
        }

        
    }
};
